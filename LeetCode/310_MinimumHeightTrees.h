#pragma once
#include "Common.h"

class Solution
{
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges)
    {
        return {};
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