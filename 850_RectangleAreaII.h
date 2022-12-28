#pragma once
#include "Common.h"

class Solution
{
public:
    int rectangleArea(vector<vector<int>> &rectangles)
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
    vector<vector<int>> rectangles = {
        {0, 0, 2, 2},
        {1, 0, 2, 3},
        {1, 0, 3, 1},
    };
    EXPECT_EQ(solution.rectangleArea(rectangles), 6);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<vector<int>> rectangles = {
        {0, 0, 1000000000, 1000000000},
    };
    EXPECT_EQ(solution.rectangleArea(rectangles), 49);
}