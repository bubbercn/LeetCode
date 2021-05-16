#pragma once
#include "Common.h"

class Solution
{
public:
    int hammingDistance(int x, int y)
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
    EXPECT_EQ(solution.hammingDistance(1, 4), 2);
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.hammingDistanc(3, 1), 1);
}