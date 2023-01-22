#pragma once
#include "Common.h"

class Solution
{
public:
    int mirrorReflection(int p, int q)
    {
        int c = commonFactor(p, q);
        int y = q / c;
        int x = p / c;
        if (y % 2 == 0)
        {
            return 0;
        }
        else
        {
            return (x % 2 == 0) ? 2 : 1;
        }
    }

private:
    int commonFactor(int m, int n)
    {
        int result = n;
        while (m % n != 0)
        {
            result = m % n;
            m = n;
            n = result;
        }
        return result;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    EXPECT_EQ(solution.mirrorReflection(2, 1), 2);
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.mirrorReflection(3, 1), 1);
}