#pragma once
#include "Common.h"

class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;
        int fresh = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 2)
                {
                    for (auto &direction : directions)
                    {
                        int x = i + direction.first;
                        int y = j + direction.second;
                        if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 1)
                        {
                            q.emplace(x, y);
                        }
                    }
                }
                else if (grid[i][j] == 1)
                {
                    fresh++;
                }
            }
        }
        int result = 0;
        while (!q.empty())
        {
            result++;
            queue<pair<int, int>> nextQ;
            list<pair<int, int>> toCheck;
            while (!q.empty())
            {
                auto [i, j] = q.front();
                q.pop();
                if (grid[i][j] == 2)
                    continue;

                grid[i][j] = 2;
                fresh--;
                toCheck.emplace_back(i, j);
            }
            for (auto [i, j] : toCheck)
            {
                for (auto &direction : directions)
                {
                    int x = i + direction.first;
                    int y = j + direction.second;
                    if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 1)
                    {
                        nextQ.emplace(x, y);
                    }
                }
            }
            q.swap(nextQ);
        }
        return fresh == 0 ? result : -1;
    }

private:
    inline static vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<vector<int>> grid = {
        {2, 1, 1},
        {1, 1, 0},
        {0, 1, 1},
    };
    EXPECT_EQ(solution.orangesRotting(grid), 4);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<vector<int>> grid = {
        {2, 1, 1},
        {0, 1, 1},
        {1, 0, 1},
    };
    EXPECT_EQ(solution.orangesRotting(grid), -1);
}

TEST_F(LeetCodeTest, Example3)
{
    vector<vector<int>> grid = {
        {0, 2},
    };
    EXPECT_EQ(solution.orangesRotting(grid), 0);
}

TEST_F(LeetCodeTest, Failure1)
{
    vector<vector<int>> grid = {
        {2, 2},
        {1, 1},
        {0, 0},
        {2, 0},
    };
    EXPECT_EQ(solution.orangesRotting(grid), 1);
}