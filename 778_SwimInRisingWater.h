#pragma once
#include "Common.h"

class Solution
{
public:
    int swimInWater(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        auto cmp = [&grid](const pair<int, int> &v1, const pair<int, int> &v2)
        {
            return grid[v1.first][v1.second] < grid[v2.first][v2.second];
        };
        set<pair<int, int>, decltype(cmp)> edges(cmp);
        int result = 0;
        edges.emplace(0, 0);
        while (!edges.empty())
        {
            auto cur = *edges.begin();
            edges.erase(edges.begin());
            result = max(result, grid[cur.first][cur.second]);
            visited[cur.first][cur.second] = true;
            if (cur.first == m - 1 && cur.second == n - 1)
                return result;

            queue<pair<int, int>> q;
            q.emplace(cur);
            while (!q.empty())
            {
                auto cur = q.front();
                q.pop();
                for (int i = 0; i < 4; i++)
                {
                    int x = cur.first + dx[i];
                    int y = cur.second + dy[i];
                    if (x >= 0 && x < m && y >= 0 && y < n && !visited[x][y])
                    {
                        if (grid[x][y] > grid[cur.first][cur.second])
                        {
                            edges.emplace(x, y);
                        }
                        else
                        {
                            q.emplace(x, y);
                            visited[x][y] = true;
                            if (x == m - 1 && y == n - 1)
                                return result;
                        }
                    }
                }
            }
        }
        return -1;
    }

private:
    inline static const int dx[4] = {-1, 0, 1, 0};
    inline static const int dy[4] = {0, 1, 0, -1};
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<vector<int>> grid = {
        {0, 2},
        {1, 3},
    };
    EXPECT_EQ(solution.swimInWater(grid), 3);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<vector<int>> grid = {
        {0, 1, 2, 3, 4},
        {24, 23, 22, 21, 5},
        {12, 13, 14, 15, 16},
        {11, 17, 18, 19, 20},
        {10, 9, 8, 7, 6},
    };
    EXPECT_EQ(solution.swimInWater(grid), 16);
}