#pragma once
#include "Common.h"

class Solution
{
public:
    int kInversePairs(int n, int k)
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
    EXPECT_EQ(solution.kInversePairs(3, 0), 1);
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.kInversePairs(3, 1), 2);
}