#pragma once
#include "Common.h"

class Solution
{
public:
    vector<string> letterCasePermutation(string_view s)
    {
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] < '0' || s[i] > '9')
            {
                vector<string> cur;
                cur.emplace_back(string(s.substr(0, i)) + static_cast<char>(tolower(s[i])));
                cur.emplace_back(string(s.substr(0, i)) + static_cast<char>(toupper(s[i])));
                vector<string> next = letterCasePermutation(s.substr(i + 1));
                vector<string> result;
                for (const auto &str : cur)
                {
                    for (const auto &str2 : next)
                    {
                        result.emplace_back(str + str2);
                    }
                }
                return result;
            }
        }
        return {string(s)};
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<string> output = {"a1b2", "a1B2", "A1b2", "A1B2"};
    EXPECT_EQ(solution.letterCasePermutation("a1b2"), output);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<string> output = {"3z4", "3Z4"};
    EXPECT_EQ(solution.letterCasePermutation("3z4"), output);
}