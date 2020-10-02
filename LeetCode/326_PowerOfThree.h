#pragma once
#include "Common.h"

class Solution
{
public:
    bool isPowerOfThree(int n)
    {
        if (n == 1)
            return true;
        while (n > 1 && n % 3 == 0)
        {
            return isPowerOfThree(n / 3);
        }
        return false;;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    EXPECT_EQ(solution.isPowerOfThree(27), true);
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.isPowerOfThree(0), false);
}

TEST_F(LeetCodeTest, Example3)
{
    EXPECT_EQ(solution.isPowerOfThree(9), true);
}

TEST_F(LeetCodeTest, Example4)
{
    EXPECT_EQ(solution.isPowerOfThree(45), false);
}