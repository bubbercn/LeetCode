#pragma once
#include "Common.h"

class Solution
{
public:
    vector<string> uncommonFromSentences(string_view s1, string_view s2)
    {
        map<string_view, int> lookup;
        auto scan = [&lookup](string_view s)
        {
            size_t begin = string::npos;
            for (size_t i = 0; i < s.length(); i++)
            {
                if (s[i] != ' ')
                {
                    if (begin == string::npos)
                    {
                        begin = i;
                    }
                }
                else
                {
                    if (begin != string::npos)
                    {
                        string_view temp = s.substr(begin, i - begin);
                        lookup[temp]++;
                        begin = string::npos;
                    }
                }
            }
            if (begin != string::npos)
            {
                string_view temp = s.substr(begin, s.length() - begin);
                lookup[temp]++;
            }
        };
        scan(s1);
        scan(s2);
        vector<string> result;
        for (auto&[s, c]:lookup)
        {
            if (c == 1)
            {
                result.emplace_back(s);
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
    vector<string> output = {"sour", "sweet"};
    EXPECT_EQ(solution.uncommonFromSentences("this apple is sweet", "this apple is sour"), output);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<string> output = {"banana"};
    EXPECT_EQ(solution.uncommonFromSentences("apple apple", "banana"), output);
}