#pragma once
#include "Common.h"

class Solution
{
public:
    int arrangeCoins(int n)
    {
        long left = 1;
        long right = n;

        while (left <= right)
        {
            long middle = (left + right) / 2;
            long value = (middle + 1) * middle / 2;
            if (value == n)
            {
                return middle;
            }
            else if (value > n)
            {
                right = middle - 1;
            }
            else
            {
                left = middle + 1;
            }
        }

        return left - 1;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    EXPECT_EQ(solution.arrangeCoins(5), 2);
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.arrangeCoins(8), 3);
}

TEST_F(LeetCodeTest, Failure1)
{
    EXPECT_EQ(solution.arrangeCoins(1804289383), 3);
}