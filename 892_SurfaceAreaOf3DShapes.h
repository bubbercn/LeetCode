#pragma once
#include "Common.h"

class Solution
{
public:
    int surfaceArea(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int result = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j])
                    result += 2;
                result += 4 * grid[i][j];
                if (i != 0)
                {
                    result -= 2 * min(grid[i][j], grid[i - 1][j]);
                }
                if (j != 0)
                {
                    result -= 2 * min(grid[i][j], grid[i][j - 1]);
                }
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
        {1, 2},
        {3, 4},
    };
    EXPECT_EQ(solution.surfaceArea(grid), 34);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<vector<int>> grid = {
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1},
    };
    EXPECT_EQ(solution.surfaceArea(grid), 32);
}

TEST_F(LeetCodeTest, Example3)
{
    vector<vector<int>> grid = {
        {2, 2, 2},
        {2, 1, 2},
        {2, 2, 2},
    };
    EXPECT_EQ(solution.surfaceArea(grid), 46);
}