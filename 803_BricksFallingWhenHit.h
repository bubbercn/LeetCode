#pragma once
#include "Common.h"

class disjoint_set_union
{
public:
    disjoint_set_union(int n)
    {
        parents.assign(n, 0);
        for (int i = 0; i < n; i++)
        {
            parents[i] = i;
        }
        counts.assign(n, 1);
    }
    int find(int input) const
    {
        while (parents.at(input) != input)
        {
            input = parents.at(input);
        }
        return input;
    }
    void merge(int input1, int input2)
    {
        int parent1 = find(input1);
        int parent2 = find(input2);
        if (parent1 == parent2)
            return;

        parents.at(parent1) = parent2;
        counts.at(parent2) += counts.at(parent1);
    }
    int count(int input) const
    {
        int parent = find(input);
        return counts.at(parent);
    }
    int size() const
    {
        return parents.size();
    }

private:
    vector<int> parents;
    vector<int> counts;
};

class Solution
{
public:
    vector<int> hitBricks(vector<vector<int>> &grid, vector<vector<int>> &hits)
    {
        m = grid.size();
        n = grid[0].size();
        vector<vector<int>> orinGrid = grid;
        for (auto hit : hits)
        {
            grid[hit[0]][hit[1]] = 0;
        }
        disjoint_set_union lookup(m * n + 1);
        for (int j = 0; j < n; j++)
        {
            if (grid[0][j] == 1)
            {
                lookup.merge(hash(0, j), lookup.size() - 1);
            }
        }
        for (int i = 1; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    if (grid[i - 1][j] == 1)
                    {
                        lookup.merge(hash(i - 1, j), hash(i, j));
                    }
                    if (j - 1 >= 0 && grid[i][j - 1] == 1)
                    {
                        lookup.merge(hash(i, j - 1), hash(i, j));
                    }
                }
            }
        }
        vector<int> result(hits.size(), 0);
        for (int i = hits.size() - 1; i >= 0; i--)
        {
            int x = hits[i][0];
            int y = hits[i][1];

            if (orinGrid[x][y] == 0)
                continue;
            
            int preStableCount = lookup.count(lookup.size() - 1);

            if (x == 0)
            {
                lookup.merge(hash(x, y), lookup.size() - 1);
            }

            for (int j = 0; j < directions.size(); j++)
            {
                int nx = x + directions[j].first;
                int ny = y + directions[j].second;
                if (nx < 0 || nx >= m || ny < 0 || ny >= n || grid[nx][ny] == 0)
                    continue;
                lookup.merge(hash(x, y), hash(nx, ny));
            }

            int curStableCount = lookup.count(lookup.size() - 1);
            result[i] = max(0, curStableCount - preStableCount - 1);
            grid[x][y] = 1;
        }
        return result;
    }

private:
    int m;
    int n;
    int hash(int i, int j)
    {
        return i * n + j;
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
        {1, 0, 0, 0},
        {1, 1, 1, 0},
    };
    vector<vector<int>> hits = {
        {1, 0},
    };
    vector<int> output = {2};
    EXPECT_EQ(solution.hitBricks(grid, hits), output);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<vector<int>> grid = {
        {1, 0, 0, 0},
        {1, 1, 0, 0},
    };
    vector<vector<int>> hits = {
        {1, 1},
        {1, 0},
    };
    vector<int> output = {0, 0};
    EXPECT_EQ(solution.hitBricks(grid, hits), output);
}

TEST_F(LeetCodeTest, Failure1)
{
    vector<vector<int>> grid = {
        {1, 0, 1},
        {1, 1, 1},
    };
    vector<vector<int>> hits = {
        {0, 0},
        {0, 2},
        {1, 1},
    };
    vector<int> output = {0, 3, 0};
    EXPECT_EQ(solution.hitBricks(grid, hits), output);
}

TEST_F(LeetCodeTest, Failure2)
{
    vector<vector<int>> grid = {
        {1},
        {1},
        {1},
        {1},
        {1},
    };
    vector<vector<int>> hits = {
        {3, 0},
        {4, 0},
        {1, 0},
        {2, 0},
        {0, 0},
    };
    vector<int> output = {1, 0, 1, 0, 0};
    EXPECT_EQ(solution.hitBricks(grid, hits), output);
}