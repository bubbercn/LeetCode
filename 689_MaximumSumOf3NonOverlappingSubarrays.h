#pragma once
#include "Common.h"

class Solution
{
public:
    vector<int> maxSumOfThreeSubarrays(vector<int> &nums, int k)
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
    vector<int> nums = {1, 2, 1, 2, 6, 7, 5, 1};
    vector<int> output = {0, 3, 5};
    EXPECT_EQ(solution.maxSumOfThreeSubarrays(nums, 2), output);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> nums = {1, 2, 1, 2, 1, 2, 1, 2, 1};
    vector<int> output = {0, 2, 4};
    EXPECT_EQ(solution.maxSumOfThreeSubarrays(nums, 2), output);
}
