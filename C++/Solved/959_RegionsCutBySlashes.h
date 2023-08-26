#pragma once
#include "Common.h"

class DisjointSet2
{
private:
    std::vector<int> parent;
    int m;

public:
    DisjointSet2(int m, int n) : parent(m * n)
    {
        this->m = m;
        for (int i = 0; i < m; i++)
        {
            int temp = i * m;
            for (int j = 0; j < n; j++)
            {
                parent[temp + j] = temp + j;
            }
        }
    }
    int find(int i, int j) const
    {
        int index = i * m + j;
        return parent[index] == index ? index : find(parent[index] / m, parent[index] % m);
    }
    void merge(int i1, int j1, int i2, int j2)
    {
        parent[find(i1, j1)] = find(i2, j2);
    }
};

class Solution
{
public:
    int regionsBySlashes(vector<string> &grid)
    {
        int n = grid.size();
        DisjointSet2 ds(n + 1, n + 1);
        for (int j = 0; j < n; j++)
        {
            ds.merge(0, j, 0, j + 1);
            ds.merge(n, j, n, j + 1);
        }
        for (int i = 0; i < n; i++)
        {
            ds.merge(i, 0, i + 1, 0);
            ds.merge(i, n, i + 1, n);
        }
        int result = 1;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == '/')
                {
                    if (ds.find(i + 1, j) == ds.find(i, j + 1))
                    {
                        result++;
                    }
                    else
                    {
                        ds.merge(i + 1, j, i, j + 1);
                    }
                }
                else if (grid[i][j] == '\\')
                {
                    if (ds.find(i, j) == ds.find(i + 1, j + 1))
                    {
                        result++;
                    }
                    else
                    {
                        ds.merge(i, j, i + 1, j + 1);
                    }
                }
            }
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
    vector<string> grid = {" /", "/ "};
    EXPECT_EQ(solution.regionsBySlashes(grid), 2);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<string> grid = {" /", "  "};
    EXPECT_EQ(solution.regionsBySlashes(grid), 1);
}

TEST_F(LeetCodeTest, Example3)
{
    vector<string> grid = {"/\\", "\\/"};
    EXPECT_EQ(solution.regionsBySlashes(grid), 5);
}

TEST_F(LeetCodeTest, Failure1)
{
    vector<string> grid = {"\\/\\ ", " /\\/", " \\/ ", "/ / "};
    EXPECT_EQ(solution.regionsBySlashes(grid), 3);
}