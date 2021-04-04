#pragma once
#include "Common.h"

class Solution
{
public:
    vector<int> findRightInterval(vector<vector<int>> &intervals)
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
    vector<vector<int>> intervals = {
        {1, 2},
    };
    vector<int> output = {-1};
    EXPECT_EQ(solution.findRightInterval(intervals), output);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<vector<int>> intervals = {
        {3, 4},
        {2, 3},
        {1, 2},
    };
    vector<int> output = {-1, 0, 1};
    EXPECT_EQ(solution.findRightInterval(intervals), output);
}

TEST_F(LeetCodeTest, Example3)
{
    vector<vector<int>> intervals = {
        {1, 4},
        {2, 3},
        {3, 4},
    };
    vector<int> output = {-1, 2, -1};
    EXPECT_EQ(solution.findRightInterval(intervals), output);
}