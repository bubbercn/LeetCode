#pragma once
#include "Common.h"

class Solution
{
public:
    double minAreaFreeRect(vector<vector<int>> &points)
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
        {1, 2},
        {2, 1},
        {1, 0},
        {0, 1},
    };
    EXPECT_EQ(solution.minAreaFreeRect(points), 2);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<vector<int>> points = {
        {0, 1},
        {2, 1},
        {1, 1},
        {1, 0},
        {2, 0},
    };
    EXPECT_EQ(solution.minAreaFreeRect(points), 1);
}

TEST_F(LeetCodeTest, Example3)
{
    vector<vector<int>> points = {
        {0, 3},
        {1, 2},
        {3, 1},
        {1, 3},
        {2, 1},
    };
    EXPECT_EQ(solution.minAreaFreeRect(points), 0);
}

TEST_F(LeetCodeTest, Failure1)
{
    vector<vector<int>> points = {
        {0, 2},
        {0, 1},
        {3, 3},
        {1, 0},
        {2, 3},
        {1, 2},
        {1, 3},
    };
    EXPECT_EQ(solution.minAreaFreeRect(points), 0);
}