#pragma once
#include "Common.h"

class Solution
{
public:
    int numMagicSquaresInside(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        int result = 0;
        for (int i = 0; i < m - 2; i++)
        {
            for (int j = 0; j < n - 2; j++)
            {
                if (helper(grid, i, j))
                    result++;
            }
        }
        return result;
    }

private:
    bool helper(const vector<vector<int>> &grid, int top, int left)
    {
        if (grid[top + 1][left + 1] != 5)
            return false;

        set<int> nums;
        for (int i = top; i < top + 3; i++)
        {
            for (int j = left; j < left + 3; j++)
            {
                nums.emplace(grid[i][j]);
            }
        }

        if (nums.size() != 9)
            return false;

        if (*nums.begin() != 1)
            return false;

        if (*nums.rbegin() != 9)
            return false;

        for (int i = top; i < top + 3; i++)
        {
            int sum = 0;
            for (int j = left; j < left + 3; j++)
            {
                sum += grid[i][j];
            }
            if (sum != 15)
                return false;
        }

        for (int j = left; j < left + 3; j++)
        {
            int sum = 0;
            for (int i = top; i < top + 3; i++)
            {
                sum += grid[i][j];
            }
            if (sum != 15)
                return false;
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
    vector<vector<int>> grid = {
        {4, 3, 8, 4},
        {9, 5, 1, 9},
        {2, 7, 6, 2},
    };
    EXPECT_EQ(solution.numMagicSquaresInside(grid), 1);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<vector<int>> grid = {
        {8},
    };
    EXPECT_EQ(solution.numMagicSquaresInside(grid), 0);
}