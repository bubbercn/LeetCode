#pragma once
#include "Common.h"

class Solution
{
public:
    int numSubarrayProductLessThanK(vector<int> &nums, int k)
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
    vector<int> nums = {10, 5, 2, 6};
    EXPECT_EQ(solution.numSubarrayProductLessThanK(nums, 100), 8);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> nums = {1, 2, 3};
    EXPECT_EQ(solution.numSubarrayProductLessThanK(nums, 0), 0);
}