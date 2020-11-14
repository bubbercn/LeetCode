#pragma once
#include "Common.h"

class Solution
{
public:
    int getSum(int a, int b)
    {
        return 0;
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