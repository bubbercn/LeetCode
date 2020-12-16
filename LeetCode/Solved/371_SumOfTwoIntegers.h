#pragma once
#include "Common.h"

class Solution
{
public:
    int getSum(int a, int b)
    {
        if ((a & b) == 0)
        {
            return a ^ b;
        }
        return getSum(a ^ b, static_cast<unsigned int>(a & b) << 1);
    }
};

class LeetCodeTest : public testing::Test
{
public:
    static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    EXPECT_EQ(solution.getSum(1, 2), 3);
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.getSum(-2, 3), 1);
}

TEST_F(LeetCodeTest, Failure1)
{
    EXPECT_EQ(solution.getSum(20, 30), 50);
}