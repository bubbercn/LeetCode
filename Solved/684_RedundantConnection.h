#pragma once
#include "Common.h"

class Solution
{
public:
    vector<int> findRedundantConnection(vector<vector<int>> &edges)
    {
        int n = edges.size();
        vector<int> lookup(n + 1, 0);
        for (int i = 1; i <= n; i++)
        {
            lookup.at(i) = i;
        }
        auto search = [&lookup](int node)
        {   
            while (lookup[node] != node)
            {
                node = lookup[node];
            }
            return node;
        };
        for (auto& edge : edges)
        {
            int index1 = search(edge[0]);
            int index2 = search(edge[1]);
            if (index1 == index2)
                return edge;
            lookup[index2] = index1;
        }
        return {};
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<vector<int>> edges = {
        {1, 2},
        {1, 3},
        {2, 3},
    };
    vector<int> output = {2, 3};
    EXPECT_EQ(solution.findRedundantConnection(edges), output);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<vector<int>> edges = {
        {1, 2},
        {2, 3},
        {3, 4},
        {1, 4},
        {1, 5},
    };
    vector<int> output = {1, 4};
    EXPECT_EQ(solution.findRedundantConnection(edges), output);
}

TEST_F(LeetCodeTest, Case1)
{
    vector<vector<int>> edges = {
        {1, 2},
        {3, 4},
        {1, 4},
        {2, 3},
        {1, 5},
    };
    vector<int> output = {2, 3};
    EXPECT_EQ(solution.findRedundantConnection(edges), output);
}