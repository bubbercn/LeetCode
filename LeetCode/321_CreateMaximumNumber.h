#pragma once
#include "Common.h"

class Solution
{
public:
    vector<int> maxNumber(vector<int> &nums1, vector<int> &nums2, int k)
    {
        return {};
    }
};

class LeetCodeTest : public testing::Test
{
public:
    static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<int> nums1 = {3, 4, 6, 5};
    vector<int> nums2 = {9, 1, 2, 5, 8, 3};
    vector<int> output = {9, 8, 6, 5, 3};
    EXPECT_EQ(solution.maxNumber(nums1, nums2, 5), output);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> nums1 = {6, 7};
    vector<int> nums2 = {6, 0, 4};
    vector<int> output = {6, 7, 6, 0, 4};
    EXPECT_EQ(solution.maxNumber(nums1, nums2, 5), output);
}

TEST_F(LeetCodeTest, Example3)
{
    vector<int> nums1 = {3, 9};
    vector<int> nums2 = {8, 9};
    vector<int> output = {9, 8, 9};
    EXPECT_EQ(solution.maxNumber(nums1, nums2, 3), output);
}
