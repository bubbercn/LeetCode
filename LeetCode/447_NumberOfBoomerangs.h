#pragma once
#include "Common.h"

class Solution
{
public:
    int numberOfBoomerangs(vector<vector<int>> &points)
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
        {0, 0},
        {1, 0},
        {2, 0},
    };
    EXPECT_EQ(solution.numberOfBoomerangs(points), 2);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<vector<int>> points = {
        {1, 1},
        {2, 2},
        {3, 3},
    };
    EXPECT_EQ(solution.numberOfBoomerangs(points), 2);
}

TEST_F(LeetCodeTest, Example3)
{
    vector<vector<int>> points = {
        {1, 1},
    };
    EXPECT_EQ(solution.numberOfBoomerangs(points), 0);
}