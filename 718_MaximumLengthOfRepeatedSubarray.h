#pragma once
#include "Common.h"

class Solution
{
public:
    int findLength(vector<int> &nums1, vector<int> &nums2)
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
    vector<int> nums1 = {1, 2, 3, 2, 1};
    vector<int> nums2 = {3, 2, 1, 4, 7};
    EXPECT_EQ(solution.findLength(nums1, nums2), 3);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> nums1 = {0, 0, 0, 0, 0};
    vector<int> nums2 = {0, 0, 0, 0, 0};
    EXPECT_EQ(solution.findLength(nums1, nums2), 5);
}