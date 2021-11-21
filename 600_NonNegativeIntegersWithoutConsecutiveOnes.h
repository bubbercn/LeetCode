#pragma once
#include "Common.h"

class Solution
{
public:
    int findIntegers(int n)
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
    EXPECT_EQ(solution.findIntegers(5), 5);
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.findIntegers(1), 2);
}

TEST_F(LeetCodeTest, Example3)
{
    EXPECT_EQ(solution.findIntegers(2), 3);
}