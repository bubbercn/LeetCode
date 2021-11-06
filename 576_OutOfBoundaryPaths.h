#pragma once
#include "Common.h"

class Solution
{
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn)
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
    EXPECT_EQ(solution.findPaths(2, 2, 2, 0, 0), 6);
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.findPaths(1, 3, 3, 0, 1), 12);
}