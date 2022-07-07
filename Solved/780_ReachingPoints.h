#pragma once
#include "Common.h"

class Solution
{
public:
    bool reachingPoints(int sx, int sy, int tx, int ty)
    {
        if (sx > tx || sy > ty)
            return false;

        while (tx > sx && ty > sy)
        {
            if (tx == ty)
                return false;

            if (tx > ty)
            {
                tx %= ty;
            }
            else
            {
                ty %= tx;
            }
        }
        if (tx == sx && ty == sy)
            return true;

        if (tx == sx)
            return (ty - sy) % sx == 0;

        if (ty == sy)
            return (tx - sx) % sy == 0;

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