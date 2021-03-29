#pragma once
#include "Common.h"

class Solution
{
public:
    int eraseOverlapIntervals(vector<vector<int> > &intervals)
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
    vector<vector<int> > intervals = {
        {1, 2},
        {2, 3},
        {3, 4},
        {1, 3},
    };
    EXPECT_EQ(solution.eraseOverlapIntervals(intervals), 1);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<vector<int> > intervals = {
        {1, 2},
        {1, 2},
        {1, 2},
    };
    EXPECT_EQ(solution.eraseOverlapIntervals(intervals), 2);
}

TEST_F(LeetCodeTest, Example3)
{
    vector<vector<int> > intervals = {
        {1, 2},
        {2, 3},
    };
    EXPECT_EQ(solution.eraseOverlapIntervals(intervals), 0);
}