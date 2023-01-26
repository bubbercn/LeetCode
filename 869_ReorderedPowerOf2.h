#pragma once
#include "Common.h"

class Solution
{
public:
    bool reorderedPowerOf2(int n)
    {
        return false;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    EXPECT_EQ(solution.reorderedPowerOf2(1), true);
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.reorderedPowerOf2(10), false);
}