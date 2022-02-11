#pragma once
#include "Common.h"

class Solution
{
public:
    double knightProbability(int n, int k, int row, int column)
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
    EXPECT_EQ(solution.knightProbability(3, 2, 0, 0), 0.06250);
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.knightProbability(1, 0, 0, 0), 1.00000);
}