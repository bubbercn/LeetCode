#pragma once
#include "Common.h"

class Solution
{
public:
    int minSwap(vector<int> &nums1, vector<int> &nums2)
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
    vector<int> nums1 = {1, 3, 5, 4};
    vector<int> nums2 = {1, 2, 3, 7};
    EXPECT_EQ(solution.minSwap(nums1, nums2), 1);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> nums1 = {0, 3, 5, 8, 9};
    vector<int> nums2 = {2, 1, 4, 6, 9};
    EXPECT_EQ(solution.minSwap(nums1, nums2), 1);
}