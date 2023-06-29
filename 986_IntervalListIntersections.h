#pragma once
#include "Common.h"

class Solution
{
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>> &firstList, vector<vector<int>> &secondList)
    {
        auto i = firstList.begin();
        auto j = secondList.begin();
        vector<vector<int>> result;
        while (i != firstList.end() && j != secondList.end())
        {
            int low = max((*i)[0], (*j)[0]);
            int high = min((*i)[1], (*j)[1]);
            if (low <= high)
            {
                result.emplace_back(vector<int>{low, high});
            }
            if ((*i)[1] < (*j)[1])
            {
                i++;
            }
            else
            {
                j++;
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
    vector<vector<int>> firstList = {{0, 2}, {5, 10}, {13, 23}, {24, 25}};
    vector<vector<int>> secondList = {{1, 5}, {8, 12}, {15, 24}, {25, 26}};
    vector<vector<int>> output = {{1, 2}, {5, 5}, {8, 10}, {15, 23}, {24, 24}, {25, 25}};
    EXPECT_EQ(solution.intervalIntersection(firstList, secondList), output);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<vector<int>> firstList = {{1, 3}, {5, 9}};
    vector<vector<int>> secondList = {};
    vector<vector<int>> output = {};
    EXPECT_EQ(solution.intervalIntersection(firstList, secondList), output);
}