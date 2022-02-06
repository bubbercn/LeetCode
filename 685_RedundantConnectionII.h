#pragma once
#include "Common.h"

class disjoint_set_union
{
public:
    disjoint_set_union(int n)
    {
        data.assign(n, 0);
        for (int i = 0; i < n; i++)
        {
            data[i] = i;
        }
    }
    int find(int input)
    {
        while (data.at(input) != input)
        {
            input = data.at(input);
        }
        return input;
    }
    int merge(int input1, int input2)
    {
        return data.at(input2) = input1;
    }
    int peek(int input)
    {
        return data.at(input);
    }
    void reset()
    {
        for (int i = 0; i < data.size(); i++)
        {
            data[i] = i;
        }
    }

private:
    vector<int> data;
};

class Solution
{
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>> &edges)
    {
        int n = edges.size();
        auto resolveConflict = [&edges, &n](const vector<int> edge1, const vector<int> edge2)
        {
            disjoint_set_union dsu(n + 1);
            for (auto &edge : edges)
            {
                if (edge == edge2)
                    continue;
                int root1 = dsu.find(edge[0]);
                int root2 = dsu.find(edge[1]);
                if (root1 == root2)
                    return edge1;
                dsu.merge(edge[0], edge[1]);
            }
            return edge2;
        };
        disjoint_set_union dsu(n + 1);
        for (auto &edge : edges)
        {
            int parent2 = dsu.peek(edge[1]);
            if (parent2 != edge[1])
            {
                return resolveConflict({dsu.peek(edge[1]), edge[1]}, edge);
            }
            dsu.merge(edge[0], edge[1]);
        }
        dsu.reset();
        for (auto &edge : edges)
        {
            int root1 = dsu.find(edge[0]);
            int root2 = dsu.find(edge[1]);
            if (root1 == root2)
                return edge;
            dsu.merge(edge[0], edge[1]);
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
    EXPECT_EQ(solution.findRedundantDirectedConnection(edges), output);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<vector<int>> edges = {
        {1, 2},
        {2, 3},
        {3, 4},
        {4, 1},
        {1, 5},
    };
    vector<int> output = {4, 1};
    EXPECT_EQ(solution.findRedundantDirectedConnection(edges), output);
}

TEST_F(LeetCodeTest, Failure1)
{
    vector<vector<int>> edges = {
        {2, 1},
        {3, 1},
        {4, 2},
        {1, 4},
    };
    vector<int> output = {2, 1};
    EXPECT_EQ(solution.findRedundantDirectedConnection(edges), output);
}

TEST_F(LeetCodeTest, Failure2)
{
    vector<vector<int>> edges = {
        {3, 4},
        {4, 1},
        {1, 2},
        {2, 3},
        {5, 1},
    };
    vector<int> output = {4, 1};
    EXPECT_EQ(solution.findRedundantDirectedConnection(edges), output);
}