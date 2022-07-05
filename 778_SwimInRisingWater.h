#pragma once
#include "Common.h"

class Solution
{
public:
    int swimInWater(vector<vector<int>> &grid)
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
        {0, 2},
        {1, 3},
    };
    EXPECT_EQ(solution.swimInWater(grid), 3);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<vector<int>> grid = {
        {0, 1, 2, 3, 4},
        {24, 23, 22, 21, 5},
        {12, 13, 14, 15, 16},
        {11, 17, 18, 19, 20},
        {10, 9, 8, 7, 6},
    };
    EXPECT_EQ(solution.swimInWater(grid), 16);
}