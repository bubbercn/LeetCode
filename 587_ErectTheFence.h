#pragma once
#include "Common.h"

class Solution
{
public:
    vector<vector<int>> outerTrees(vector<vector<int>> &trees)
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
    vector<vector<int>> trees = {
        {1, 1},
        {2, 2},
        {2, 0},
        {2, 4},
        {3, 3},
        {4, 2},
    };
    vector<vector<int>> output = {
        {1, 1},
        {2, 0},
        {3, 3},
        {2, 4},
        {4, 2},
    };
    EXPECT_EQ(solution.outerTrees(trees), output);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<vector<int>> trees = {
        {1, 2},
        {2, 2},
        {4, 2},
    };
    vector<vector<int>> output = {
        {4, 2},
        {2, 2},
        {1, 2},
    };
    EXPECT_EQ(solution.outerTrees(trees), output);
}