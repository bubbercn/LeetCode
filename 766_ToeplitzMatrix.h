#pragma once
#include "Common.h"

class Solution
{
public:
    bool isToeplitzMatrix(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (matrix[i][j] != matrix[i - 1][j - 1])
                    return false;
            }
        }
        return true;
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

TEST_F(LeetCodeTest, Failure1)
{
    vector<vector<int>> matrix = {
        {36, 59, 71, 15, 26, 82, 87},
        {56, 36, 59, 71, 15, 26, 82},
        {15, 0, 36, 59, 71, 15, 26},
    };
    EXPECT_EQ(solution.isToeplitzMatrix(matrix), false);
}