#pragma once
#include "Common.h"

class Solution
{
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges)
    {
        if (n == 0)
            return {};

        vector<Vertex> vertexes(n);
        for (auto &edge : edges)
        {
            vertexes[edge[0]].degree++;
            vertexes[edge[0]].adjacentVertexes.emplace_back(edge[1]);
            vertexes[edge[1]].degree++;
            vertexes[edge[1]].adjacentVertexes.emplace_back(edge[0]);
        }

        set<int> result;
        for (int i = 0; i < n; i++)
        {
            result.emplace(i);
        }

        list<int> vertexesToRemove;
        for (auto i : result)
        {
            if (vertexes[i].degree == 1)
            {
                vertexesToRemove.emplace_back(i);
            }
        }

        while (result.size() > 2)
        {
            list<int> vertexesToRemoveNext;
            for (auto vertex : vertexesToRemove)
            {
                result.erase(vertex);
                for (auto i : vertexes[vertex].adjacentVertexes)
                {
                    vertexes[i].degree--;
                    if (vertexes[i].degree == 1)
                    {
                        vertexesToRemoveNext.emplace_back(i);
                    }
                }
            }
            vertexesToRemove.swap(vertexesToRemoveNext);
        }

        return {result.begin(), result.end()};
    }

private:
    struct Vertex
    {
        int degree;
        vector<int> adjacentVertexes;
    };
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