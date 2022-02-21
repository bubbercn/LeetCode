#pragma once
#include "Common.h"

class Solution
{
public:
    bool canPartitionKSubsets(vector<int> &nums, int k)
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
    vector<int> nums = {4, 3, 2, 3, 5, 2, 1};
    EXPECT_EQ(solution.canPartitionKSubsets(nums, 4), true);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> nums = {1, 2, 3, 4};
    EXPECT_EQ(solution.canPartitionKSubsets(nums, 3), false);
}
