#pragma once
#include "Common.h"

class Solution
{
public:
    int matrixScore(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0; i < m; i++)
        {
            if (grid[i][0] == 0)
            {
                for (int j = 0; j < n; j++)
                {
                    grid[i][j] = grid[i][j] == 0 ? 1 : 0;
                }
            }
        }
        int base = pow(2, n - 1);
        int result = base * m;
        for (int j = 1; j < n; j++)
        {
            base >>= 1;
            int count = 0;
            for (int i = 0; i < m; i++)
            {
                if (grid[i][j])
                    count++;
            }
            count = max(count, m - count);
            result += base * count;
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
        {0, 0, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 0},
    };
    EXPECT_EQ(solution.matrixScore(grid), 39);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<vector<int>> grid = {
        {0},
    };
    EXPECT_EQ(solution.matrixScore(grid), 1);
}