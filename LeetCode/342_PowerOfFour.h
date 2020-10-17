#pragma once
#include "Common.h"

class Solution
{
public:
    bool isPowerOfFour(int num)
    {
        while (num > 1)
        {
            if (num % 4 != 0)
                return false;
            num >>= 2;
        }

        if (num <= 0)
            return false;

        return true;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    EXPECT_EQ(solution.isPowerOfFour(16), true);
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.isPowerOfFour(5), false);
}