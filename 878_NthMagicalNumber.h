#pragma once
#include "Common.h"

class Solution
{
public:
    int nthMagicalNumber(int n, int a, int b)
    {
        return 0;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    EXPECT_EQ(solution.nthMagicalNumber(1, 2, 3), 2);
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.nthMagicalNumber(4, 2, 3), 6);
}