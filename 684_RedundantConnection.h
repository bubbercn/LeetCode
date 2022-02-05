#pragma once
#include "Common.h"

class Solution
{
public:
    vector<int> findRedundantConnection(vector<vector<int>> &edges)
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