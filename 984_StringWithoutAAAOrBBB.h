#pragma once
#include "Common.h"

class Solution
{
public:
    string strWithout3a3b(int a, int b)
    {
        return {};
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    EXPECT_EQ(solution.strWithout3a3b(1, 2), "abb");
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.strWithout3a3b(4, 1), "aabaa");
}