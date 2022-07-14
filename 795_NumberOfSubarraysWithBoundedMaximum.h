#pragma once
#include "Common.h"

class Solution
{
public:
    int numSubarrayBoundedMax(vector<int> &nums, int left, int right)
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
    vector<int> nums = {2, 1, 4, 3};
    EXPECT_EQ(solution.numSubarrayBoundedMax(nums, 2, 3), 3);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> nums = {2, 9, 2, 5, 6};
    EXPECT_EQ(solution.numSubarrayBoundedMax(nums, 2, 8), 7);
}