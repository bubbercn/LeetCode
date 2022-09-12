#pragma once
#include "Common.h"

class Solution
{
public:
    double largestTriangleArea(vector<vector<int>> &points)
    {
        double result = 0;
        int n = points.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                for (int k = j + 1; k < n; k++)
                {
                    double s = 0.5 * abs(points[i][0] * points[j][1] + points[j][0] * points[k][1] + points[k][0] * points[i][1] - points[i][0] * points[k][1] - points[j][0] * points[i][1] - points[k][0] * points[j][1]);
                    result = max(result, s);
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
    vector<vector<int>> points = {{0, 0}, {0, 1}, {1, 0}, {0, 2}, {2, 0}};
    EXPECT_EQ(solution.largestTriangleArea(points), 2);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<vector<int>> points = {{1, 0}, {0, 0}, {0, 1}};
    EXPECT_EQ(solution.largestTriangleArea(points), 0.5);
}