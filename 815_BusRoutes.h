#pragma once
#include "Common.h"

class Solution
{
public:
    int numBusesToDestination(vector<vector<int>> &routes, int source, int target)
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
    vector<vector<int>> routes = {
        {1, 2, 7},
        {3, 6, 7},
    };
    EXPECT_EQ(solution.numBusesToDestination(routes, 1, 6), 2);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<vector<int>> routes = {
        {7, 12},
        {4, 5, 15},
        {6},
        {15, 19},
        {9, 12, 13},
    };
    EXPECT_EQ(solution.numBusesToDestination(routes, 15, 12), -1);
}