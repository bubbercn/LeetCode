#pragma once
#include "Common.h"

class Solution
{
public:
    vector<int> eventualSafeNodes(vector<vector<int>> &graph)
    {
        unordered_map<int, unordered_set<int>> graphMap;
        unordered_map<int, unordered_set<int>> lookup;
        vector<int> safeNodes;
        for (int i = 0; i < graph.size(); i++)
        {
            if (graph[i].empty())
            {
                safeNodes.emplace_back(i);
                continue;
            }
            unordered_set<int> &nodes = graphMap[i];
            for (int j = 0; j < graph[i].size(); j++)
            {
                nodes.emplace(graph[i][j]);
                lookup[graph[i][j]].emplace(i);
            }
        }
        vector<int> result;
        while (!safeNodes.empty())
        {
            result.insert(result.end(), safeNodes.begin(), safeNodes.end());
            vector<int> nextSafeNodes;
            for (auto node : safeNodes)
            {
                if (auto it = lookup.find(node); it != lookup.end())
                {
                    for (auto neighbor : it->second)
                    {
                        graphMap[neighbor].erase(node);
                        if (graphMap[neighbor].empty())
                        {
                            nextSafeNodes.emplace_back(neighbor);
                            graphMap.erase(neighbor);
                            lookup.erase(neighbor);
                        }
                    }
                }
            }
            safeNodes.swap(nextSafeNodes);
        }
        sort(result.begin(), result.end());
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
    vector<vector<int>> graph = {
        {1, 2},
        {2, 3},
        {5},
        {0},
        {5},
        {},
        {},
    };
    vector<int> output = {2, 4, 5, 6};
    EXPECT_EQ(solution.eventualSafeNodes(graph), output);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<vector<int>> graph = {
        {1, 2, 3, 4},
        {1, 2},
        {3, 4},
        {0, 4},
        {},
    };
    vector<int> output = {4};
    EXPECT_EQ(solution.eventualSafeNodes(graph), output);
}