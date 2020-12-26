#pragma once
#include "Common.h"

class Solution
{
public:
    bool isRectangleCover(vector<vector<int>> &rectangles)
    {
        return false;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
    inline static vector<vector<int>> rectangles;
};

TEST_F(LeetCodeTest, Example1)
{
    rectangles = {
        {1, 1, 3, 3},
        {3, 1, 4, 2},
        {3, 2, 4, 4},
        {1, 3, 2, 4},
        {2, 3, 3, 4}};
    EXPECT_EQ(solution.isRectangleCover(rectangles), true);
}

TEST_F(LeetCodeTest, Example2)
{
    rectangles = {
        {1, 1, 2, 3},
        {1, 3, 2, 4},
        {3, 1, 4, 2},
        {3, 2, 4, 4}};
    EXPECT_EQ(solution.isRectangleCover(rectangles), false);
}

TEST_F(LeetCodeTest, Example3)
{
    rectangles = {
        {1, 1, 3, 3},
        {3, 1, 4, 2},
        {1, 3, 2, 4},
        {3, 2, 4, 4}};
    EXPECT_EQ(solution.isRectangleCover(rectangles), false);
}

TEST_F(LeetCodeTest, Example4)
{
    rectangles = {
        {1, 1, 3, 3},
        {3, 1, 4, 2},
        {1, 3, 2, 4},
        {2, 2, 4, 4}};
    EXPECT_EQ(solution.isRectangleCover(rectangles), false);
}