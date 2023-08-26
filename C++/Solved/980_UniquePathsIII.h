#pragma once
#include "Common.h"

class Solution
{
public:
    int uniquePathsIII(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        lookup.assign(m, vector<vector<int>>(n, vector<int>(1 << (m * n), -1)));
        bitset<400> visited;
        auto start = findStart(grid, visited);
        visited.set(start.first * n + start.second);
        return dfs(start, grid, visited);
    }

private:
    int dfs(const pair<int, int> &start, vector<vector<int>> &grid, bitset<400> &visited)
    {
        int state = visited.to_ulong();
        if (lookup[start.first][start.second][state] != -1)
        {
            return lookup[start.first][start.second][state];
        }

        int m = grid.size();
        int n = grid[0].size();
        int result = 0;
        if (grid[start.first][start.second] == 2)
        {
            if (visited.count() == m * n)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }

        for (auto &direction : directions)
        {
            int x = start.first + direction.first;
            int y = start.second + direction.second;
            if (x >= 0 && x < m && y >= 0 && y < n && !visited.test(x * n + y))
            {
                visited.set(x * n + y);
                result += dfs({x, y}, grid, visited);
                visited.reset(x * n + y);
            }
        }
        lookup[start.first][start.second][state] = result;
        return result;
    }

    pair<int, int> findStart(vector<vector<int>> &grid, bitset<400> &visited)
    {
        int m = grid.size();
        int n = grid[0].size();
        pair<int, int> result = {-1, -1};
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    result = {i, j};
                }
                else if (grid[i][j] == -1)
                {
                    visited.set(i * n + j);
                }
            }
        }
        return result;
    }

    inline static const vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    vector<vector<vector<int>>> lookup;
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<vector<int>> grid = {{1, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 2, -1}};
    EXPECT_EQ(solution.uniquePathsIII(grid), 2);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<vector<int>> grid = {{1, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 2}};
    EXPECT_EQ(solution.uniquePathsIII(grid), 4);
}

TEST_F(LeetCodeTest, Example3)
{
    vector<vector<int>> grid = {{0, 1}, {2, 0}};
    EXPECT_EQ(solution.uniquePathsIII(grid), 0);
}