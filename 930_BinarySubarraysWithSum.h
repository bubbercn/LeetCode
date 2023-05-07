#pragma once
#include "Common.h"

class Solution
{
public:
    int numSubarraysWithSum(vector<int> &nums, int goal)
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
    vector<int> nums = {1, 0, 1, 0, 1};
    EXPECT_EQ(solution.numSubarraysWithSum(nums, 2), 4);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> nums = {0, 0, 0, 0, 0};
    EXPECT_EQ(solution.numSubarraysWithSum(nums, 0), 15);
}