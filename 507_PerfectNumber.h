#pragma once
#include "Common.h"

class Solution
{
public:
    bool checkPerfectNumber(int num)
    {
        if (num == 1)
            return false;

        int sum = 1;
        for (int i = 2; i * i <= num; i++)
        {
            if (num % i == 0)
            {
                sum += i;
                if (int d = num / i; d != i)
                {
                    sum += d;
                }
            }

            if (sum > num)
                return false;
        }
        return sum == num;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    EXPECT_EQ(solution.checkPerfectNumber(28), true);
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.checkPerfectNumber(6), true);
}

TEST_F(LeetCodeTest, Example3)
{
    EXPECT_EQ(solution.checkPerfectNumber(496), true);
}

TEST_F(LeetCodeTest, Example4)
{
    EXPECT_EQ(solution.checkPerfectNumber(8128), true);
}

TEST_F(LeetCodeTest, Example5)
{
    EXPECT_EQ(solution.checkPerfectNumber(2), false);
}