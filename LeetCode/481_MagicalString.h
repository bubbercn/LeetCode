#pragma once
#include "Common.h"

class Solution
{
public:
    int magicalString(int n)
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
    EXPECT_EQ(solution.magicalString(6), 3);
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.magicalString(1), 1);
}