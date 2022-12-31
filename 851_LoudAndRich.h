#pragma once
#include "Common.h"

class Solution
{
public:
    vector<int> loudAndRich(vector<vector<int>> &richer, vector<int> &quiet)
    {
        unordered_map<int, unordered_set<int>> graph;
        unordered_map<int, int> cache;
        for (auto &edge : richer)
        {
            graph[edge[1]].emplace(edge[0]);
        }
        cache.clear();
        int n = quiet.size();
        vector<int> result(n);
        for (int i = 0; i < n; i++)
        {
            result[i] = dfs(graph, cache, quiet, i);
        }
        return result;
    }

private:
    int dfs(const unordered_map<int, unordered_set<int>> &graph, unordered_map<int, int> &cache, const vector<int> &quiet, int n)
    {
        if (auto it = cache.find(n); it != cache.end())
            return it->second;

        int result = n;
        if (auto it = graph.find(n); it != graph.end())
        {
            for (auto to : it->second)
            {
                int temp = dfs(graph, cache, quiet, to);
                if (quiet[temp] < quiet[result])
                    result = temp;
            }
        }
        cache.emplace(n, result);
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
    vector<vector<int>> richer = {
        {1, 0},
        {2, 1},
        {3, 1},
        {3, 7},
        {4, 3},
        {5, 3},
        {6, 3},
    };
    vector<int> quiet = {3, 2, 5, 4, 6, 1, 7, 0};
    vector<int> output = {5, 5, 2, 5, 4, 5, 6, 7};
    EXPECT_EQ(solution.loudAndRich(richer, quiet), output);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<vector<int>> richer = {};
    vector<int> quiet = {0};
    vector<int> output = {0};
    EXPECT_EQ(solution.loudAndRich(richer, quiet), output);
}

TEST_F(LeetCodeTest, Failure1)
{
    vector<vector<int>> richer = {
        {0, 2},
        {1, 2},
    };
    vector<int> quiet = {1, 0, 2};
    vector<int> output = {0, 1, 1};
    EXPECT_EQ(solution.loudAndRich(richer, quiet), output);
}