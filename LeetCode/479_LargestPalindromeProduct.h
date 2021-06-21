#pragma once
#include "Common.h"

class Solution
{
public:
    int largestPalindrome(int n)
    {
        return 0;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    EXPECT_EQ(solution.largestPalindrome(2), 987);
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.largestPalindrome(1), 9);
}