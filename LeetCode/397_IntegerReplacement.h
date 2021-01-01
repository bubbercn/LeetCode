#pragma once
#include "Common.h"

class Solution
{
public:
    int integerReplacement(int n)
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