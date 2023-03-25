#pragma once
#include "Common.h"

class Solution
{
public:
    int projectionArea(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int result = 0;
        for (int i = 0; i < n; i++)
        {
            int max1 = 0;
            int max2 = 0;
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j])
                    result++;
                max1 = ::max(max1, grid[i][j]);
                max2 = ::max(max2, grid[j][i]);
            }
            result += max1;
            result += max2;
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
    EXPECT_EQ(solution.projectionArea(grid), 17);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<vector<int>> grid = {
        {2},
    };
    EXPECT_EQ(solution.projectionArea(grid), 5);
}

TEST_F(LeetCodeTest, Example3)
{
    vector<vector<int>> grid = {
        {1, 0},
        {0, 2},
    };
    EXPECT_EQ(solution.projectionArea(grid), 8);
}