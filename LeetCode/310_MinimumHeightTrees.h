#pragma once
#include "Common.h"

class Solution
{
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges)
    {
        if (n == 0)
            return {};

        vector<vector<int>> distances(n, vector<int>(n, INT_MAX));
        for (auto& edge : edges)
        {
            distances[edge[1]][edge[0]] = 1;
            distances[edge[0]][edge[1]] = 1;
        }

        for (int k = 0; k < n; k++)
        {
            distances[k][k] = 0;
        }

        for (int k = 0; k < n; k++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (distances[i][k] != INT_MAX && distances[k][j] != INT_MAX)
                    {
                        distances[i][j] = min(distances[i][j], distances[i][k] + distances[k][j]);
                    }
                }
            }
        }

        int minTreeDepth = INT_MAX;
        vector<int> result;
        for(int i = 0; i < n; i++)
        {
            int treeDepth = 0;
            for (int j = 0; j < n; j++)
            {
                if (i != j)
                {
                    treeDepth = max(treeDepth, distances[i][j]);
                }
            }
            if (treeDepth < minTreeDepth)
            {
                result.clear();
                result.emplace_back(i);
                minTreeDepth = treeDepth;
            }
            else if (treeDepth == minTreeDepth)
            {
                result.emplace_back(i);
            }
        }

        return result;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    int n = 4;
    vector<vector<int>> edges = {{1, 0}, {1, 2}, {1, 3}};
    vector<int> output = {1};
    EXPECT_EQ(solution.findMinHeightTrees(n, edges), output);
}

TEST_F(LeetCodeTest, Example2)
{
    int n = 6;
    vector<vector<int>> edges = {{3, 0}, {3, 1}, {3, 2}, {3, 4}, {5, 4}};
    vector<int> output = {3, 4};
    EXPECT_EQ(solution.findMinHeightTrees(n, edges), output);
}

TEST_F(LeetCodeTest, Example3)
{
    int n = 1;
    vector<vector<int>> edges = {};
    vector<int> output = {0};
    EXPECT_EQ(solution.findMinHeightTrees(n, edges), output);
}

TEST_F(LeetCodeTest, Example4)
{
    int n = 2;
    vector<vector<int>> edges = {{0, 1}};
    vector<int> output = {0, 1};
    EXPECT_EQ(solution.findMinHeightTrees(n, edges), output);
}