#pragma once
#include "Common.h"

class Solution
{
public:
    string nearestPalindromic(string n)
    {
        return {};
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    EXPECT_EQ(solution.nearestPalindromic("123"), "121");
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.nearestPalindromic("1"), "0");
}