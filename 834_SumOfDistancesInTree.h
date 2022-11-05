#pragma once
#include "Common.h"

class Solution
{
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>> &edges)
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
    vector<vector<int>> edges = {
        {0, 1},
        {0, 2},
        {2, 3},
        {2, 4},
        {2, 5},
    };
    vector<int> output = {8, 12, 6, 10, 10, 10};
    EXPECT_EQ(solution.sumOfDistancesInTree(6, edges), output);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<vector<int>> edges;
    vector<int> output = {0};
    EXPECT_EQ(solution.sumOfDistancesInTree(1, edges), output);
}

TEST_F(LeetCodeTest, Example3)
{
    vector<vector<int>> edges = {
        {1, 0},
    };
    vector<int> output = {1, 1};
    EXPECT_EQ(solution.sumOfDistancesInTree(2, edges), output);
}