#pragma once
#include "Common.h"

class Solution
{
public:
    int reachableNodes(vector<vector<int>> &edges, int maxMoves, int n)
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
    vector<vector<int>> edges = {
        {0, 1, 10},
        {0, 2, 1},
        {1, 2, 2},
    };
    EXPECT_EQ(solution.reachableNodes(edges, 6, 3), 13);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<vector<int>> edges = {
        {0, 1, 4},
        {1, 2, 6},
        {0, 2, 8},
        {1, 3, 1},
    };
    EXPECT_EQ(solution.reachableNodes(edges, 10, 4), 23);
}

TEST_F(LeetCodeTest, Example3)
{
    vector<vector<int>> edges = {
        {1, 2, 4},
        {1, 4, 5},
        {1, 3, 1},
        {2, 3, 4},
        {3, 4, 5},
    };
    EXPECT_EQ(solution.reachableNodes(edges, 17, 5), 11);
}