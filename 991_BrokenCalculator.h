#pragma once
#include "Common.h"

class Solution
{
public:
    int brokenCalc(int startValue, int target)
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
    EXPECT_EQ(solution.brokenCalc(2, 3), 2);
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.brokenCalc(5, 8), 2);
}

TEST_F(LeetCodeTest, Example3)
{
    EXPECT_EQ(solution.brokenCalc(3, 10), 3);
}