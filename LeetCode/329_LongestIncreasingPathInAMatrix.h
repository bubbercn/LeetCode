#pragma once
#include "Common.h"

class Solution
{
public:
    int longestIncreasingPath(vector<vector<int>> &matrix)
    {
        return 0;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<vector<int>> nums = {
        {9, 9, 4},
        {6, 6, 8},
        {2, 1, 1}};
    EXPECT_EQ(solution.longestIncreasingPath(nums), 4);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<vector<int>> nums = {
        {3, 4, 5},
        {3, 2, 6},
        {2, 2, 1}};
    EXPECT_EQ(solution.longestIncreasingPath(nums), 4);
}
