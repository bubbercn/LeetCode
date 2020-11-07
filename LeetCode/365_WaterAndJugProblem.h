#pragma once
#include "Common.h"

class Solution
{
public:
    bool canMeasureWater(int x, int y, int z)
    {
        return false;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    EXPECT_EQ(solution.canMeasureWater(3, 5, 4), true);
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.canMeasureWater(2, 6, 5), false);
}