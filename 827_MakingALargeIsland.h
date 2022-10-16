#pragma once
#include "Common.h"

class Solution
{
public:
    int largestIsland(vector<vector<int>> &grid)
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
        {1, 0},
        {0, 1},
    };
    EXPECT_EQ(solution.largestIsland(grid), 3);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<vector<int>> grid = {
        {1, 1},
        {1, 0},
    };
    EXPECT_EQ(solution.largestIsland(grid), 4);
}

TEST_F(LeetCodeTest, Example3)
{
    vector<vector<int>> grid = {
        {1, 1},
        {1, 1},
    };
    EXPECT_EQ(solution.largestIsland(grid), 4);
}