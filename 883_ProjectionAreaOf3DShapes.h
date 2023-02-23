#pragma once
#include "Common.h"

class Solution
{
public:
    int projectionArea(vector<vector<int>> &grid)
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
    vector<vector<int>> grid = {
        {1, 2},
        {3, 4},
    };
    EXPECT_EQ(solution.projectionArea(grid), 17);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<vector<int>> grid = {
        {2},
    };
    EXPECT_EQ(solution.projectionArea(grid), 5);
}

TEST_F(LeetCodeTest, Example3)
{
    vector<vector<int>> grid = {
        {1, 0},
        {0, 2},
    };
    EXPECT_EQ(solution.projectionArea(grid), 8);
}