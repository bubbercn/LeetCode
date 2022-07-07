#pragma once
#include "Common.h"

class Solution
{
public:
    bool reachingPoints(int sx, int sy, int tx, int ty)
    {
        return false;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    EXPECT_EQ(solution.reachingPoints(1, 1, 3, 5), true);
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.reachingPoints(1, 1, 2, 2), false);
}

TEST_F(LeetCodeTest, Example3)
{
    EXPECT_EQ(solution.reachingPoints(1, 1, 1, 1), true);
}