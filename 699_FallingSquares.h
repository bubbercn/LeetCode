#pragma once
#include "Common.h"

class Solution
{
public:
    vector<int> fallingSquares(vector<vector<int>> &positions)
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
    vector<vector<int>> positions = {
        {1, 2},
        {2, 3},
        {6, 1},
    };
    vector<int> output = {2, 5, 5};
    EXPECT_EQ(solution.fallingSquares(positions), output);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<vector<int>> positions = {
        {100, 100},
        {200, 100},
    };
    vector<int> output = {100, 100};
    EXPECT_EQ(solution.fallingSquares(positions), output);
}
