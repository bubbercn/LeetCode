#pragma once
#include "Common.h"

class Solution
{
public:
    bool isBipartite(vector<vector<int>> &graph)
    {
        return false;
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
        {0, 2},
        {0, 1, 3},
        {0, 2},
    };
    EXPECT_EQ(solution.isBipartite(graph), false);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<vector<int>> graph = {
        {1, 3},
        {0, 2},
        {1, 3},
        {0, 2},
    };
    EXPECT_EQ(solution.isBipartite(graph), true);
}