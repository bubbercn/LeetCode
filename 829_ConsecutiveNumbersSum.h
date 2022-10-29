#pragma once
#include "Common.h"

class Solution
{
public:
    int consecutiveNumbersSum(int n)
    {
        int result = 0;
        for (int i = 1; i * i <= n; i++)
        {
            if (n % i == 0)
            {
                if (i & 1)
                    result++;
                int temp = n / i;
                if (temp != i && (temp & 1))
                    result++;
            }
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
    EXPECT_EQ(solution.consecutiveNumbersSum(5), 2);
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.consecutiveNumbersSum(9), 3);
}

TEST_F(LeetCodeTest, Example3)
{
    EXPECT_EQ(solution.consecutiveNumbersSum(15), 4);
}
