#pragma once
#include "Common.h"

class Solution
{
public:
    int fib(int n)
    {
        if (n == 0)
            return 0;
        
        if (n == 1)
            return 1;

        int p = 1, pp = 0;
        int result;
        for (int i = 2; i <= n; i++)
        {
            result = p + pp;
            pp = p;
            p = result;
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
    EXPECT_EQ(solution.fib(2), 1);
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.fib(3), 2);
}

TEST_F(LeetCodeTest, Example3)
{
    EXPECT_EQ(solution.fib(4), 3);
}