#pragma once
#include "Common.h"

class Solution
{
public:
    int islandPerimeter(vector<vector<int>> &grid)
    {
        int result = 0;
        for (size_t i = 0; i < grid.size(); i++)
        {
            for (size_t j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == 0)
                    continue;
                if (i == 0 || grid[i - 1][j] == 0)
                    result++;
                if (j == 0 || grid[i][j - 1] == 0)
                    result++;
                if (i == grid.size() - 1 || grid[i + 1][j] == 0)
                    result++;
                if (j == grid[0].size() - 1 || grid[i][j + 1] == 0)
                    result++;
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
        {0, 1, 0, 0},
        {1, 1, 1, 0},
        {0, 1, 0, 0},
        {1, 1, 0, 0},
    };
    EXPECT_EQ(solution.islandPerimeter(grid), 16);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<vector<int>> grid = {{1}};
    EXPECT_EQ(solution.islandPerimeter(grid), 4);
}

TEST_F(LeetCodeTest, Example3)
{
    vector<vector<int>> grid = {{1, 0}};
    EXPECT_EQ(solution.islandPerimeter(grid), 4);
}
