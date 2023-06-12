#pragma once
#include "Common.h"

class Solution
{
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
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
    vector<vector<int>> points = {{1, 3}, {-2, 2}};
    vector<vector<int>> output = {{-2, 2}};
    EXPECT_EQ(solution.kClosest(points, 1), output);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<vector<int>> points = {{3, 3}, {5, -1}, {-2, 4}};
    vector<vector<int>> output = {{3, 3}, {-2, 4}};
    EXPECT_EQ(solution.kClosest(points, 2), output);
}