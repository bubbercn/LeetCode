#pragma once
#include "Common.h"

class Solution
{
public:
    int minAreaRect(vector<vector<int>> &points)
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
        {1, 1},
        {1, 3},
        {3, 1},
        {3, 3},
        {2, 2},
    };
    EXPECT_EQ(solution.minAreaRect(points), 4);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<vector<int>> points = {
        {1, 1},
        {1, 3},
        {3, 1},
        {3, 3},
        {4, 1},
        {4, 3},
    };
    EXPECT_EQ(solution.minAreaRect(points), 2);
}