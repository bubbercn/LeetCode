#pragma once
#include "Common.h"

class Solution
{
public:
    bool isValid(string_view code)
    {
        cmatch m;
        bool match = regex_match(code.data(), m, CODE);
        if (!match)
            return false;

        return isValidContent(m[2].str());
    }

private:
    bool isValidContent(string_view content)
    {
        stack<pair<string, int>> tags;
        for (int i = 0; i < content.size();)
        {
            if (content[i] == '<')
            {
                cmatch m;
                bool match = false;
                if (content[i + 1] == '!')
                {
                    // cdata
                    match = regex_search(&content[i], m, CDATA, regex_constants::match_continuous);
                    if (!match)
                        return false;
                }
                else if (content[i + 1] == '/')
                {
                    // end tag
                    match = regex_search(&content[i], m, END_TAG, regex_constants::match_continuous);
                    if (!match)
                        return false;

                    string tagName = m[1].str();
                    if (tags.empty() || tags.top().first != tagName)
                        return false;

                    if (tags.size() == 1)
                    {
                        match = isValidContent(content.substr(tags.top().second, i - tags.top().second));
                        if (!match)
                            return false;
                    }

                    tags.pop();
                }
                else
                {
                    // start tag
                    match = regex_search(&content[i], m, START_TAG, regex_constants::match_continuous);
                    if (!match)
                        return false;
                    string tagName = m[1].str();
                    tags.emplace(tagName, i + m.length());
                }
                i += m.length();
            }
            else
            {
                i++;
            }
        }
        return tags.empty();
    }
    inline static regex CDATA{R"(<!\[CDATA\[.*?\]\]>)"};
    inline static regex START_TAG{R"(<([A-Z]{1,9})>)"};
    inline static regex END_TAG{R"(</([A-Z]{1,9})>)"};
    inline static regex CODE{R"(<([A-Z]{1,9})>(.*)</\1>)"};
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    EXPECT_EQ(solution.isValid("<DIV>This is the first line <![CDATA[<div>]]></DIV>"), true);
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.isValid("<DIV>>>  ![cdata[]] <![CDATA[<div>]>]]>]]>>]</DIV>"), true);
}

TEST_F(LeetCodeTest, Example3)
{
    EXPECT_EQ(solution.isValid("<A>  <B> </A>   </B>"), false);
}

TEST_F(LeetCodeTest, Example4)
{
    EXPECT_EQ(solution.isValid("<DIV>  div tag is not closed  <DIV>"), false);
}

TEST_F(LeetCodeTest, CDATA)
{
    EXPECT_EQ(solution.isValid("<DIV><![CDATA[CDATA_CONTENT]]>]]></DIV>"), true);
}

TEST_F(LeetCodeTest, Failure1)
{
    EXPECT_EQ(solution.isValid("<A><A>456</A>  <A> 123  !!  <![CDATA[]]>  123 </A>   <A>123</A></A>"), true);
}

TEST_F(LeetCodeTest, Failure2)
{
    EXPECT_EQ(solution.isValid("<DIV><DIV></DIV><hello></hello><DIV></DIV></DIV>"), false);
}