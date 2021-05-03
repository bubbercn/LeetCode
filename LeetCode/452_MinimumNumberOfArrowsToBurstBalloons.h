#pragma once
#include "Common.h"

class Solution
{
public:
    int findMinArrowShots(vector<vector<int>> &points)
    {
        auto cmp = [](const vector<int> &l, vector<int> &r) {
            return l[1] < r[1];
        };
        sort(points.begin(), points.end(), cmp);
        int arrow = 0;
        int result = 0;
        for (int i = 0; i < points.size(); i++)
        {
            if (i == 0)
            {
                arrow = points[0][1];
                result++;
            }
            else
            {
                if (points[i][0] > arrow)
                {
                    arrow = points[i][1];
                    result++;
                }
            }
        }
        return result;
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
        {10, 16},
        {2, 8},
        {1, 6},
        {7, 12},
    };
    EXPECT_EQ(solution.findMinArrowShots(points), 2);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<vector<int>> points = {
        {1, 2},
        {3, 4},
        {5, 6},
        {7, 8},
    };
    EXPECT_EQ(solution.findMinArrowShots(points), 4);
}

TEST_F(LeetCodeTest, Example3)
{
    vector<vector<int>> points = {
        {1, 2},
        {2, 3},
        {3, 4},
        {4, 5},
    };
    EXPECT_EQ(solution.findMinArrowShots(points), 2);
}