#pragma once
#include "Common.h"

class Solution
{
public:
    int atMostNGivenDigitSet(vector<string> &digits, int n)
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
    vector<string> digits = {"1", "3", "5", "7"};
    EXPECT_EQ(solution.atMostNGivenDigitSet(digits, 100), 20);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<string> digits = {"1", "4", "9"};
    EXPECT_EQ(solution.atMostNGivenDigitSet(digits, 1000000000), 29523);
}