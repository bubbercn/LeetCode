#pragma once
#include "Common.h"

class Solution
{
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> maxRow(m, 0);
        for (int i = 0; i < m; i++)
        {
            int max = 0;
            for (int j = 0; j < n; j++)
            {
                max = ::max(max, grid[i][j]);
            }
            maxRow[i] = max;
        }

        vector<int> maxColum(n, 0);
        for (int j = 0; j < n; j++)
        {
            int max = 0;
            for (int i = 0; i < m; i++)
            {
                max = ::max(max, grid[i][j]);
            }
            maxColum[j] = max;
        }

        int result = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                result += min(maxRow[i], maxColum[j]) - grid[i][j];
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
    vector<vector<int>> grid = {
        {3, 0, 8, 4},
        {2, 4, 5, 7},
        {9, 2, 6, 3},
        {0, 3, 1, 0},
    };
    EXPECT_EQ(solution.maxIncreaseKeepingSkyline(grid), 35);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<vector<int>> grid = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0},
    };
    EXPECT_EQ(solution.maxIncreaseKeepingSkyline(grid), 0);
}