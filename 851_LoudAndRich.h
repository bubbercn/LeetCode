#pragma once
#include "Common.h"

class Solution
{
public:
    vector<int> loudAndRich(vector<vector<int>> &richer, vector<int> &quiet)
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
    vector<vector<int>> richer = {
        {1, 0},
        {2, 1},
        {3, 1},
        {3, 7},
        {4, 3},
        {5, 3},
        {6, 3},
    };
    vector<int> quiet = {3, 2, 5, 4, 6, 1, 7, 0};
    vector<int> output = {5, 5, 2, 5, 4, 5, 6, 7};
    EXPECT_EQ(solution.loudAndRich(richer, quiet), output);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<vector<int>> richer = {};
    vector<int> quiet = {0};
    vector<int> output = {0};
    EXPECT_EQ(solution.loudAndRich(richer, quiet), output);
}