#pragma once
#include "Common.h"

class Solution
{
public:
    int catMouseGame(vector<vector<int>> &graph)
    {
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
        {2, 5},
        {3},
        {0, 4, 5},
        {1, 4, 5},
        {2, 3},
        {0, 2, 3},
    };
    EXPECT_EQ(solution.catMouseGame(graph), 0);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<vector<int>> graph = {
        {1, 3},
        {0},
        {3},
        {0, 2},
    };
    EXPECT_EQ(solution.catMouseGame(graph), 0);
}