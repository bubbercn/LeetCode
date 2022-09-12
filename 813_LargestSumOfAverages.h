#pragma once
#include "Common.h"

class Solution
{
public:
    double largestSumOfAverages(vector<int> &nums, int k)
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
    vector<int> nums = {9, 1, 2, 3, 9};
    EXPECT_EQ(solution.largestSumOfAverages(nums, 3), 20);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    EXPECT_EQ(solution.largestSumOfAverages(nums, 4), 20.5);
}