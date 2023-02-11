#pragma once
#include "Common.h"

class Solution
{
public:
    int shortestPathAllKeys(vector<string> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        using Keys = bitset<6>;
        int x, y;
        unordered_map<char, int> keyToIndex;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == '@')
                {
                    x = i;
                    y = j;
                }
                else if (islower(grid[i][j]))
                {
                    keyToIndex[grid[i][j]] = keyToIndex.size();
                }
            }
        }
        vector<vector<vector<bool>>> visited(m, vector<vector<bool>>(n, vector<bool>(1 << keyToIndex.size())));
        list<tuple<int, int, int>> q;
        q.emplace_back(x, y, 0);
        visited[x][y][0] = true;
        int result = 0;
        while (!q.empty())
        {
            list<tuple<int, int, int>> nextQ;
            for (auto [x, y, state] : q)
            {
                if (state == (1 << keyToIndex.size()) - 1)
                {
                    return result;
                }
                for (auto [dx, dy] : directions)
                {
                    int nextX = x + dx;
                    int nextY = y + dy;
                    int nextState = state;
                    if (nextX < 0 || nextX >= m || nextY < 0 || nextY >= n || grid[nextX][nextY] == '#')
                        continue;
                    if (grid[nextX][nextY] != '.' && grid[nextX][nextY] != '@')
                    {
                        bitset<6> bits(state);
                        if (islower(grid[nextX][nextY]))
                        {
                            if (!bits.test(keyToIndex[grid[nextX][nextY]]))
                                nextState += (1 << keyToIndex[grid[nextX][nextY]]);
                        }
                        else
                        {
                            if (!bits.test(keyToIndex[tolower(grid[nextX][nextY])]))
                                continue;
                        }
                    }
                    if (visited[nextX][nextY][nextState])
                        continue;
                    nextQ.emplace_back(nextX, nextY, nextState);
                    visited[nextX][nextY][nextState] = true;
                }
            }
            q.swap(nextQ);
            result++;
        }
        return -1;
    }

private:
    inline static vector<pair<int, int>> directions{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<string> grid = {"@.a..", "###.#", "b.A.B"};
    EXPECT_EQ(solution.shortestPathAllKeys(grid), 8);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<string> grid = {"@..aA", "..B#.", "....b"};
    EXPECT_EQ(solution.shortestPathAllKeys(grid), 6);
}

TEST_F(LeetCodeTest, Example3)
{
    vector<string> grid = {"@Aa"};
    EXPECT_EQ(solution.shortestPathAllKeys(grid), -1);
}

TEST_F(LeetCodeTest, Failure1)
{
    vector<string> grid = {"@...a", ".###A", "b.BCc"};
    EXPECT_EQ(solution.shortestPathAllKeys(grid), 10);
}