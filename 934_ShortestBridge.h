#pragma once
#include "Common.h"

class Solution
{
public:
    int shortestBridge(vector<vector<int>> &grid)
    {
        list<pair<int, int>> toVisit;
        markOneIsland(grid, toVisit);
        int n = grid.size();
        int result = 0;
        while (true)
        {
            list<pair<int, int>> next;
            for (auto [x, y] : toVisit)
            {
                for (auto [dx, dy] : directions)
                {
                    int nx = x + dx;
                    int ny = y + dy;
                    if (nx < 0 or nx >= n or ny < 0 or ny >= n or grid[nx][ny] == -1)
                        continue;

                    if (grid[nx][ny] == 1)
                        return result;

                    grid[nx][ny] = -1;
                    next.emplace_back(nx, ny);
                }
            }
            result++;
            toVisit.swap(next);
        }
        return result;
    }

private:
    void markOneIsland(vector<vector<int>> &grid, list<pair<int, int>> &toVisit)
    {
        int n = grid.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    dfs(grid, i, j, toVisit);
                    return;
                }
            }
        }
    }
    void dfs(vector<vector<int>> &grid, int x, int y, list<pair<int, int>> &toVisit)
    {
        int n = grid.size();
        if (x < 0 or x >= n or y < 0 or y >= n or grid[x][y] != 1)
            return;

        grid[x][y] = -1;
        toVisit.emplace_back(x, y);
        for (auto [dx, dy] : directions)
        {
            dfs(grid, x + dx, y + dy, toVisit);
        }
    }

    inline static vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<vector<int>> grid = {
        {0, 1},
        {1, 0},
    };
    EXPECT_EQ(solution.shortestBridge(grid), 1);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<vector<int>> grid = {
        {0, 1, 0},
        {0, 0, 0},
        {0, 0, 1},
    };
    EXPECT_EQ(solution.shortestBridge(grid), 2);
}

TEST_F(LeetCodeTest, Example3)
{
    vector<vector<int>> grid = {
        {1, 1, 1, 1, 1},
        {1, 0, 0, 0, 1},
        {1, 0, 1, 0, 1},
        {1, 0, 0, 0, 1},
        {1, 1, 1, 1, 1},
    };
    EXPECT_EQ(solution.shortestBridge(grid), 1);
}