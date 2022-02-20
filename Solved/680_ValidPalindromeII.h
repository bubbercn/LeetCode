#pragma once
#include "Common.h"

class Solution
{
public:
    bool validPalindrome(string_view s)
    {
        for (int begin = 0, end = s.length() - 1; begin <= end; begin++, end--)
        {
            if (s[begin] != s[end])
                return helper(s.substr(begin + 1, end - begin)) || helper(s.substr(begin, end - begin));
        }
        return true;
    }
    bool helper(string_view s)
    {
        for (int begin = 0, end = s.length() - 1; begin <= end; begin++, end--)
        {
            if (s[begin] != s[end])
                return false;
        }
        return true;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    EXPECT_EQ(solution.validPalindrome("aba"), true);
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.validPalindrome("abca"), true);
}

TEST_F(LeetCodeTest, Example3)
{
    EXPECT_EQ(solution.validPalindrome("abc"), false);
}
