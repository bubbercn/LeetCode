#pragma once
#include "Common.h"

class Solution
{
public:
    vector<vector<int>> transpose(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> result(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                result [i][j] = matrix[j][i];
            }
        }
        return result;
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
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
    };
    vector<vector<int>> output = {
        {1, 4, 7},
        {2, 5, 8},
        {3, 6, 9},
    };
    EXPECT_EQ(solution.transpose(matrix), output);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
    };
    vector<vector<int>> output = {
        {1, 4},
        {2, 5},
        {3, 6},
    };
    EXPECT_EQ(solution.transpose(matrix), output);
}