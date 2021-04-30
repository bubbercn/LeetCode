#pragma once
#include "Common.h"

class Solution
{
public:
    int findMinArrowShots(vector<vector<int>> &points)
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
    vector<vector<int>> points = {
        {10, 16},
        {2, 8},
        {1, 6},
        {7, 12},
    };
    EXPECT_EQ(solution.findMinArrowShots(points), 2);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<vector<int>> points = {
        {1, 2},
        {3, 4},
        {5, 6},
        {7, 8},
    };
    EXPECT_EQ(solution.findMinArrowShots(points), 4);
}

TEST_F(LeetCodeTest, Example3)
{
    vector<vector<int>> points = {
        {1, 2},
        {2, 3},
        {3, 4},
        {4, 5},
    };
    EXPECT_EQ(solution.findMinArrowShots(points), 2);
}