#pragma once
#include "Common.h"

class Solution
{
public:
    vector<int> hitBricks(vector<vector<int>> &grid, vector<vector<int>> &hits)
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
    vector<vector<int>> grid = {
        {1, 0, 0, 0},
        {1, 1, 1, 0},
    };
    vector<vector<int>> hits = {
        {1, 0},
    };
    vector<int> output = {2};
    EXPECT_EQ(solution.hitBricks(grid, hits), output);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<vector<int>> grid = {
        {1, 0, 0, 0},
        {1, 1, 0, 0},
    };
    vector<vector<int>> hits = {
        {1, 1},
        {1, 0},
    };
    vector<int> output = {0, 0};
    EXPECT_EQ(solution.hitBricks(grid, hits), output);
}