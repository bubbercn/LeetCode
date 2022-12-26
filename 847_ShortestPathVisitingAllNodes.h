#pragma once
#include "Common.h"

class Solution
{
public:
    int shortestPathLength(vector<vector<int>> &graph)
    {
        using State = tuple<int, bitset<12>, int>;
        int n = graph.size();
        vector<vector<bool>> history(n, vector<bool>(1 << n));
        queue<State> next;
        for (int i = 0; i < n; i++)
        {
            next.emplace(i, bitset<12>(1 << i), 0);
            history[i][1 << i] = true;
        }
        while (!next.empty())
        {
            auto [cur, state, dis] = next.front();
            next.pop();

            if (state.count() == n)
                return dis;

            for (auto adj : graph[cur])
            {
                bitset<12> temp = state;
                temp.set(adj);
                if (history[adj][temp.to_ulong()])
                    continue;
                history[adj][temp.to_ulong()] = true;
                next.emplace(adj, temp, dis + 1);
            }
        }
        return 0;
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
        {0},
        {0},
        {0},
    };
    EXPECT_EQ(solution.shortestPathLength(graph), 4);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<vector<int>> graph = {
        {1},
        {0, 2, 4},
        {1, 3, 4},
        {2},
        {1, 2},
    };
    EXPECT_EQ(solution.shortestPathLength(graph), 4);
}