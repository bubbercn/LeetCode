#pragma once
#include "Common.h"

class Solution
{
public:
    int getMoneyAmount(int n)
    {
        return 0;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    EXPECT_EQ(solution.getMoneyAmount(10), 16);
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.getMoneyAmount(1), 0);
}

TEST_F(LeetCodeTest, Example3)
{
    EXPECT_EQ(solution.getMoneyAmount(2), 1);
}