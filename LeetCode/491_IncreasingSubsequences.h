#pragma once
#include "Common.h"

class Solution
{
public:
    vector<vector<int>> findSubsequences(vector<int> &nums)
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
    vector<int> nums = {4, 6, 7, 7};
    vector<vector<int>> output = {
        {4, 6},
        {4, 6, 7},
        {4, 6, 7, 7},
        {4, 7},
        {4, 7, 7},
        {6, 7},
        {6, 7, 7},
        {7, 7},
    };
    EXPECT_EQ(solution.findSubsequences(nums), output);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> nums = {4, 4, 3, 2, 1};
    vector<vector<int>> output = {
        {4, 4},
    };
    EXPECT_EQ(solution.findSubsequences(nums), output);
}