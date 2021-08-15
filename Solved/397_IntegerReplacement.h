#pragma once
#include "Common.h"

class Solution
{
public:
    int integerReplacement(int n)
    {
        if (n == 1)
            return 0;
        if (n == 2)
            return 1;
        if (n == 3)
            return 2;
        if ((n & 1) == 0)
            return integerReplacement(n / 2) + 1;
        if ((n + 1l) && 0x3 == 0)
            return integerReplacement(n + 1) + 1;
        return integerReplacement(n - 1) + 1;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    EXPECT_EQ(solution.integerReplacement(8), 3);
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.integerReplacement(7), 4);
}

TEST_F(LeetCodeTest, Example3)
{
    EXPECT_EQ(solution.integerReplacement(4), 2);
}