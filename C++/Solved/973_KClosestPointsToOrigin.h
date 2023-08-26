#pragma once
#include "Common.h"

class Solution
{
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
    {
        auto cmp = [](const pair<int, int> &v1, const pair<int, int> &v2)
        {
            return v1.first < v2.first;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> maxHeap(cmp);
        for (int i = 0; i < points.size(); i++)
        {
            maxHeap.emplace(points[i][0] * points[i][0] + points[i][1] * points[i][1], i);
            if (maxHeap.size() > k)
            {
                maxHeap.pop();
            }
        }
        vector<vector<int>> result;
        while (!maxHeap.empty())
        {
            result.emplace_back(points[maxHeap.top().second]);
            maxHeap.pop();
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
    vector<vector<int>> points = {{1, 3}, {-2, 2}};
    vector<vector<int>> output = {{-2, 2}};
    EXPECT_EQ(solution.kClosest(points, 1), output);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<vector<int>> points = {{3, 3}, {5, -1}, {-2, 4}};
    vector<vector<int>> output = {{-2, 4}, {3, 3}};
    EXPECT_EQ(solution.kClosest(points, 2), output);
}