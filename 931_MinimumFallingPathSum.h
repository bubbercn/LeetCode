#pragma once
#include "Common.h"

class Solution
{
public:
    int minFallingPathSum(vector<vector<int>> &matrix)
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
    vector<vector<int>> matrix = {
        {2, 1, 3},
        {6, 5, 4},
        {7, 8, 9},
    };
    EXPECT_EQ(solution.minFallingPathSum(matrix), 13);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<vector<int>> matrix = {
        {-19, 57},
        {-40, -5},
    };
    EXPECT_EQ(solution.minFallingPathSum(matrix), -59);
}