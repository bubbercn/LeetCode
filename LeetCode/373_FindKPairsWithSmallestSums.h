#pragma once
#include "Common.h"

class Solution
{
public:
    vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k)
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
    vector<int> nums1 = {1, 7, 11};
    vector<int> nums2 = {2, 4, 6};
    vector<vector<int>> output = {{1, 2}, {1, 4}, {1, 6}};
    EXPECT_EQ(solution.kSmallestPairs(nums1, nums2, 3), output);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> nums1 = {1, 1, 2};
    vector<int> nums2 = {1, 2, 3};
    vector<vector<int>> output = {{1, 1}, {1, 1}};
    EXPECT_EQ(solution.kSmallestPairs(nums1, nums2, 2), output);
}

TEST_F(LeetCodeTest, Example3)
{
    vector<int> nums1 = {1, 2};
    vector<int> nums2 = {3};
    vector<vector<int>> output = {{1, 3}, {2, 3}};
    EXPECT_EQ(solution.kSmallestPairs(nums1, nums2, 3), output);
}