#pragma once
#include "Common.h"

class Solution
{
public:
    double new21Game(int n, int k, int maxPts)
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
    EXPECT_EQ(solution.new21Game(10, 1, 10), 1);
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.new21Game(6, 1, 10), 0.6);
}

TEST_F(LeetCodeTest, Example3)
{
    EXPECT_EQ(solution.new21Game(21, 17, 10), 0.73278);
}
