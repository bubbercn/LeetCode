#pragma once
#include "Common.h"

class Solution
{
public:
    int nextGreaterElement(int n)
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
    EXPECT_EQ(solution.nextGreaterElement(12), 21);
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.nextGreaterElement(21), -1);
}