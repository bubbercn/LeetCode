#pragma once
#include "Common.h"

class Solution
{
public:
    int intersectionSizeTwo(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end(), [](const vector<int> &v1, const vector<int> &v2)
             {
            if (v1[0] == v2[0])
            {
                return v1[1] > v2[1];
            }
            return v1[0] < v2[0]; });
        int result = 0;
        int left1, left2;
        for (int i = intervals.size() - 1; i >= 0; i--)
        {
            if (i == intervals.size() - 1 || intervals[i][1] < left1)
            {
                left1 = intervals[i][0];
                left2 = left1 + 1;
                result += 2;
            }
            else if (intervals[i][1] >= left1 && intervals[i][1] < left2)
            {
                if (intervals[i][0] == left1)
                {
                    left2 = left1 + 1;
                }
                else
                {
                    left2 = left1;
                    left1 = intervals[i][0];
                }
                result++;
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
    vector<vector<int>> intervals = {
        {1, 3},
        {1, 4},
        {2, 5},
        {3, 5},
    };
    EXPECT_EQ(solution.intersectionSizeTwo(intervals), 3);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<vector<int>> intervals = {
        {1, 2},
        {2, 3},
        {2, 4},
        {4, 5},
    };
    EXPECT_EQ(solution.intersectionSizeTwo(intervals), 5);
}

TEST_F(LeetCodeTest, Failure1)
{
    vector<vector<int>> intervals = {
        {6, 21},
        {1, 15},
        {15, 20},
        {10, 21},
        {0, 7},
    };
    EXPECT_EQ(solution.intersectionSizeTwo(intervals), 4);
}
