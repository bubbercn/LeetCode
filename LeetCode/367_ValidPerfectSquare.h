#pragma once
#include "Common.h"

class Solution
{
public:
    bool isPerfectSquare(int num)
    {
        if (num == 1)
            return true;
        for (int i = 2; i * i < num; i++)
        {
            
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