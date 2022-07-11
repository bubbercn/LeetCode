#pragma once
#include "Common.h"

class Solution
{
public:
    bool isBipartite(vector<vector<int>> &graph)
    {
        int n = graph.size();
        vector<int> node2Color(n, -1);
        for (int i = 0; i < n; i++)
        {
            if (node2Color[i] == -1 && !dfs(graph, node2Color, i, 0))
                return false;
        }
        return true;
    }

private:
    bool dfs(vector<vector<int>> &graph, vector<int> &node2Color, int node, int color)
    {
        if (node2Color[node] != -1)
            return node2Color[node] == color;
        node2Color[node] = color;
        for (int neighbor : graph[node])
        {
            if (!dfs(graph, node2Color, neighbor, 1 - color))
                return false;
        }
        return true;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<vector<int>> graph = {
        {1, 2, 3},
        {0, 2},
        {0, 1, 3},
        {0, 2},
    };
    EXPECT_EQ(solution.isBipartite(graph), false);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<vector<int>> graph = {
        {1, 3},
        {0, 2},
        {1, 3},
        {0, 2},
    };
    EXPECT_EQ(solution.isBipartite(graph), true);
}