#pragma once
#include "Common.h"

class Solution
{
public:
    vector<int> eventualSafeNodes(vector<vector<int>> &graph)
    {
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