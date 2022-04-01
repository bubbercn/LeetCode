#pragma once
#include "Common.h"

class Solution
{
public:
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        int result = 0;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 0 || visited[i][j])
                    continue;

                result = max(result, bfs(grid, i, j, visited));
            }
        }
        return result;
    }

private:
    int bfs(const vector<vector<int>> &grid, int x, int y, vector<vector<bool>> &visited)
    {
        const static vector<pair<int, int>> moves = {
            {-1, 0},
            {1, 0},
            {0, -1},
            {0, 1},
        };
        int m = grid.size();
        int n = grid[0].size();
        visited[x][y] = true;
        list<pair<int, int>> current = {{x, y}};
        int result = 1;
        while (!current.empty())
        {
            list<pair<int, int>> next;
            for (auto [x, y] : current)
            {
                for (auto [dx, dy] : moves)
                {
                    int posX = x + dx;
                    int posY = y + dy;
                    if (posX < 0 || posX >= m || posY < 0 || posY >= n)
                        continue;

                    if (grid[posX][posY] == 0 || visited[posX][posY])
                        continue;

                    next.emplace_back(posX, posY);
                    visited[posX][posY] = true;
                    result++;
                }
            }
            current.swap(next);
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
        {0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
        {0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0},
        {0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0},
    };
    EXPECT_EQ(solution.maxAreaOfIsland(grid), 6);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<vector<int>> grid = {
        {0, 0, 0, 0, 0, 0, 0, 0},
    };
    EXPECT_EQ(solution.maxAreaOfIsland(grid), 0);
}

TEST_F(LeetCodeTest, Failure1)
{
    vector<vector<int>> grid = {
        {1, 1, 0, 0, 0},
        {1, 1, 0, 0, 0},
        {0, 0, 0, 1, 1},
        {0, 0, 0, 1, 1},
    };
    EXPECT_EQ(solution.maxAreaOfIsland(grid), 4);
}