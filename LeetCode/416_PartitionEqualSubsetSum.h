#pragma once
#include "Common.h"

class Solution
{
public:
    bool canPartition(vector<int> &nums)
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
    vector<int> nums = {1, 5, 11, 5};
    EXPECT_EQ(solution.canPartition(nums), true);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> nums = {1, 2, 3, 5};
    EXPECT_EQ(solution.canPartition(nums), false);
}