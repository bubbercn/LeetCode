#pragma once
#include "Common.h"

class Solution
{
public:
    void dfs(int node, int from)
    {
        treeSize[node] = 1;
        for (auto to : graph[node])
        {
            if (to == from)
            {
                continue;
            }
            dfs(to, node);
            dp[node] += dp[to] + treeSize[to];
            treeSize[node] += treeSize[to];
        }
    }

    void dfs2(int node, int from)
    {
        result[node] = dp[node];
        for (auto to : graph[node])
        {
            if (to == from)
            {
                continue;
            }
            int nodeDp = dp[node];
            int toDp = dp[to];
            int nodeSize = treeSize[node];
            int toSize = treeSize[to];

            dp[node] -= dp[to] + treeSize[to];
            treeSize[node] -= treeSize[to];
            dp[to] += dp[node] + treeSize[node];
            treeSize[to] += treeSize[node];

            dfs2(to, node);

            dp[node] = nodeDp;
            dp[to] = toDp;
            treeSize[node] = nodeSize;
            treeSize[to] = toSize;
        }
    }

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>> &edges)
    {
        result = vector<int>(n);
        treeSize = vector<int>(n);
        dp = vector<int>(n);
        graph = vector<list<int>>(n);
        for (auto &edge : edges)
        {
            int node = edge[0], to = edge[1];
            graph[node].emplace_back(to);
            graph[to].emplace_back(node);
        }
        dfs(0, -1);
        dfs2(0, -1);
        return result;
    }

private:
    vector<int> result;
    vector<int> treeSize;
    vector<int> dp;
    vector<list<int>> graph;
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<vector<int>> edges = {
        {0, 1},
        {0, 2},
        {2, 3},
        {2, 4},
        {2, 5},
    };
    vector<int> output = {8, 12, 6, 10, 10, 10};
    EXPECT_EQ(solution.sumOfDistancesInTree(6, edges), output);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<vector<int>> edges;
    vector<int> output = {0};
    EXPECT_EQ(solution.sumOfDistancesInTree(1, edges), output);
}

TEST_F(LeetCodeTest, Example3)
{
    vector<vector<int>> edges = {
        {1, 0},
    };
    vector<int> output = {1, 1};
    EXPECT_EQ(solution.sumOfDistancesInTree(2, edges), output);
}