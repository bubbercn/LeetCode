#pragma once
#include "Common.h"

class Solution
{
public:
    bool isPerfectSquare(int num)
    {
        if (num == 1)
            return true;
        for (long i = 2; i * i <= num; i++)
        {
            if (num % i == 0)
            {
                num /= i;
                if (num % i != 0)
                    return false;
                num /= i;
                return isPerfectSquare(num);
            }
        }
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
    EXPECT_EQ(solution.isPerfectSquare(16), true);
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.isPerfectSquare(14), false);
}

TEST_F(LeetCodeTest, Failure1)
{
    EXPECT_EQ(solution.isPerfectSquare(2147483647), false);
}