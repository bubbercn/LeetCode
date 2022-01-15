#pragma once
#include "Common.h"

class Solution
{
public:
    int findKthNumber(int m, int n, int k)
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
    EXPECT_EQ(solution.findKthNumber(3, 3, 5), 3);
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.findKthNumber(2, 3, 6), 6);
}