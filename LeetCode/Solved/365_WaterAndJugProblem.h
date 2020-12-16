#pragma once
#include "Common.h"

class Solution
{
public:
    bool canMeasureWater(int x, int y, int z)
    {
        if (x + y < z)
        {
            return false;
        }
        if (x == 0 || y == 0)
        {
            return z == 0 || x + y == z;
        }
        return z % gcd(x, y) == 0;
    }

private:
    int gcd(int x, int y)
    {
        int z = y;
        while (x % y != 0)
        {
            z = x % y;
            x = y;
            y = z;
        }
        return z;
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

TEST_F(LeetCodeTest, Failure1)
{
    EXPECT_EQ(solution.canMeasureWater(1, 2, 3), true);
}

TEST_F(LeetCodeTest, Failure2)
{
    EXPECT_EQ(solution.canMeasureWater(104639, 104651, 2341), true);
}
