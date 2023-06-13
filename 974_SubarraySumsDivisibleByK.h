#pragma once
#include "Common.h"

class Solution
{
public:
    int subarraysDivByK(vector<int> &nums, int k)
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
    vector<int> nums = {4, 5, 0, -2, -3, 1};
    EXPECT_EQ(solution.subarraysDivByK(nums, 5), 7);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> nums = {5};
    EXPECT_EQ(solution.subarraysDivByK(nums, 9), 0);
}