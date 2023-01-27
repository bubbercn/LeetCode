#pragma once
#include "Common.h"

class Solution
{
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>> &stations)
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
    vector<vector<int>> stations = {};
    EXPECT_EQ(solution.minRefuelStops(1, 1, stations), 0);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<vector<int>> stations = {{10, 100}};
    EXPECT_EQ(solution.minRefuelStops(100, 1, stations), -1);
}

TEST_F(LeetCodeTest, Example3)
{
    vector<vector<int>> stations = {
        {10, 60},
        {20, 30},
        {30, 30},
        {60, 40},
    };
    EXPECT_EQ(solution.minRefuelStops(100, 10, stations), 2);
}