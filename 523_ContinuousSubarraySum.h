#pragma once
#include "Common.h"

class Solution
{
public:
    bool checkSubarraySum(vector<int> &nums, int k)
    {
        return false;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<int> nums = {23, 2, 4, 6, 7};
    EXPECT_EQ(solution.checkSubarraySum(nums, 6), true);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> nums = {23, 2, 6, 4, 7};
    EXPECT_EQ(solution.checkSubarraySum(nums, 6), true);
}

TEST_F(LeetCodeTest, Example3)
{
    vector<int> nums = {23, 2, 6, 4, 7};
    EXPECT_EQ(solution.checkSubarraySum(nums, 13), false);
}