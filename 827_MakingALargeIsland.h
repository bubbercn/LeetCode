#pragma once
#include "Common.h"

class Solution
{
public:
    int largestIsland(vector<vector<int>> &grid)
    {
        int n = grid.size();
        DisjointSet ds(n * n);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 0)
                    continue;

                if (j != 0 && grid[i][j - 1] == 1)
                    ds.merge(i * n + j - 1, i * n + j);

                if (i != 0 && grid[i - 1][j] == 1)
                    ds.merge((i - 1) * n + j, i * n + j);
            }
        }

        int result = 0;
        unordered_map<int, int> lookup;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int temp = ++lookup[ds.find(i * n + j)];
                result = max(result, temp);
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                    continue;

                int temp = 1;
                unordered_set<int> neighbors;
                for (auto [dx, dy] : directions)
                {
                    int x = i + dx;
                    int y = j + dy;
                    if (x >= 0 && x < n && y >= 0 && y < n && grid[x][y] == 1)
                    {
                        int neighbor = ds.find(x * n + y);
                        if (neighbors.emplace(neighbor).second)
                            temp += lookup[neighbor];
                    }
                }
                result = max(result, temp);
            }
        }
        return result;
    }

private:
    class DisjointSet
    {
    private:
        std::vector<int> parent;

    public:
        DisjointSet(int size) : parent(size)
        {
            for (int i = 0; i < size; ++i)
            {
                parent[i] = i;
            }
        }
        int find(int index) const
        {
            return parent[index] == index ? index : find(parent[index]);
        }
        void merge(int index1, int index2)
        {
            parent[find(index2)] = find(index1);
        }
        int size() const
        {
            int size = 0;
            for (int i = 0; i < parent.size(); ++i)
            {
                if (parent[i] == i)
                {
                    size++;
                }
            }
            return size;
        }
    };
    inline static vector<pair<int, int>> directions{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<vector<int>> grid = {
        {1, 0},
        {0, 1},
    };
    EXPECT_EQ(solution.largestIsland(grid), 3);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<vector<int>> grid = {
        {1, 1},
        {1, 0},
    };
    EXPECT_EQ(solution.largestIsland(grid), 4);
}

TEST_F(LeetCodeTest, Example3)
{
    vector<vector<int>> grid = {
        {1, 1},
        {1, 1},
    };
    EXPECT_EQ(solution.largestIsland(grid), 4);
}