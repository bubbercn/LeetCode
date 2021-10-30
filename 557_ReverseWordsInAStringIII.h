#pragma once
#include "Common.h"

class Solution
{
public:
    string reverseWords(string s)
    {
        auto wordBegin = s.end();
        for (auto it = s.begin(); it != s.end(); it++)
        {
            if (*it == ' ')
            {
                reverse(wordBegin, it);
                wordBegin = s.end();
            }
            else if (wordBegin == s.end())
            {
                wordBegin = it;
            }
        }
        reverse(wordBegin, s.end());
        return s;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    EXPECT_EQ(solution.reverseWords("Let's take LeetCode contest"), "s'teL ekat edoCteeL tsetnoc");
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.reverseWords("God Ding"), "doG gniD");
}
