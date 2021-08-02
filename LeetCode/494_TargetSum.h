#pragma once
#include "Common.h"

class Solution
{
public:
    int findTargetSumWays(vector<int> &nums, int target)
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
    vector<int> nums = {1, 1, 1, 1, 1};
    EXPECT_EQ(solution.findTargetSumWays(nums, 3), 5);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> nums = {1};
    EXPECT_EQ(solution.findTargetSumWays(nums, 1), 1);
}