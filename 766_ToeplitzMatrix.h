#pragma once
#include "Common.h"

class Solution
{
public:
    bool isToeplitzMatrix(vector<vector<int>> &matrix)
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
    vector<vector<int>> matrix = {
        {1, 2, 3, 4},
        {5, 1, 2, 3},
        {9, 5, 1, 2},
    };
    EXPECT_EQ(solution.isToeplitzMatrix(matrix), true);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<vector<int>> matrix = {
        {1, 2},
        {2, 2},
    };
    EXPECT_EQ(solution.isToeplitzMatrix(matrix), false);
}