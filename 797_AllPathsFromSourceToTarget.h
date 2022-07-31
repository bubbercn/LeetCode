#pragma once
#include "Common.h"

class Solution
{
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
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
        {3},
        {3},
        {},
    };
    vector<vector<int>> output = {
        {0, 1, 3},
        {0, 2, 3},
    };
    EXPECT_EQ(solution.allPathsSourceTarget(graph), output);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<vector<int>> graph = {
        {4, 3, 1},
        {3, 2, 4},
        {3},
        {4},
        {1},
    };
    vector<vector<int>> output = {
        {0, 4},
        {0, 3, 4},
        {0, 1, 3, 4},
        {0, 1, 2, 3, 4},
        {0, 1, 4},
    };
    EXPECT_EQ(solution.allPathsSourceTarget(graph), output);
}