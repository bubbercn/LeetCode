#pragma once
#include "Common.h"

class Solution
{
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>> &mines)
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
    vector<vector<int>> mines = {{4, 2}};
    EXPECT_EQ(solution.orderOfLargestPlusSign(5, mines), 2);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<vector<int>> mines = {{0, 0}};
    EXPECT_EQ(solution.orderOfLargestPlusSign(1, mines), 0);
}