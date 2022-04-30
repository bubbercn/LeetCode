#pragma once
#include "Common.h"

class Solution
{
public:
    int cherryPickup(vector<vector<int>> &grid)
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
        {0, 1, -1},
        {1, 0, -1},
        {1, 1, 1},
    };
    EXPECT_EQ(solution.cherryPickup(grid), 5);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<vector<int>> grid = {
        {1, 1, -1},
        {1, -1, 1},
        {-1, 1, 1},
    };
    EXPECT_EQ(solution.cherryPickup(grid), 0);
}
