#pragma once
#include "Common.h"

class Solution
{
public:
    vector<double> medianSlidingWindow(vector<int> &nums, int k)
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
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    vector<double> output = {1.00000, -1.00000, -1.00000, 3.00000, 5.00000, 6.00000};
    EXPECT_EQ(solution.medianSlidingWindow(nums, 3), output);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> nums = {1, 2, 3, 4, 2, 3, 1, 4, 2};
    vector<double> output = {2.00000, 3.00000, 3.00000, 3.00000, 2.00000, 3.00000, 2.00000};
    EXPECT_EQ(solution.medianSlidingWindow(nums, 3), output);
}