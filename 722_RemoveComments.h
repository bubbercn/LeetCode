#pragma once
#include "Common.h"

class Solution
{
public:
    vector<string> removeComments(vector<string> &source)
    {
        vector<string> result;
        bool inComment = false;
        for (auto &line : source)
        {
            size_t pos = 0;
            string lineNoComment;
            while (true)
            {
                if (inComment)
                {
                    if (pos = line.find("*/", pos); pos == string::npos)
                    {
                        continue;
                    }
                    else
                    {
                        line = line.substr(pos + 2);
                    }
                }
                else
                {
                    if (auto pos = line.find("//"); pos != string::npos)
                    {
                        line = line.substr(0, pos);
                    }
                    else if (pos = line.find("/*"); pos != string::npos)
                    {
                        line = line.substr(0, pos);
                        inComment = true;
                    }
                }
                if (!line.empty())
                {
                    result.emplace_back(line);
                }
            }
        }
        return result;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<string> source = {"/*Test program */", "int main()", "{ ", "  // variable declaration ", "int a, b, c;", "/* This is a test", "   multiline  ", "   comment for ", "   testing */", "a = b + c;", "}"};
    vector<string> output = {"int main()", "{ ", "  ", "int a, b, c;", "a = b + c;", "}"};
    EXPECT_EQ(solution.removeComments(source), output);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<string> source = {"a/*comment", "line", "more_comment*/b"};
    vector<string> output = {"ab"};
    EXPECT_EQ(solution.removeComments(source), output);
}