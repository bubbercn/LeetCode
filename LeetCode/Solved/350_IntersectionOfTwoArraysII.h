#pragma once
#include "Common.h"

class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_multiset<int> lookup;
        for (int i : nums1)
        {
            lookup.emplace(i);
        }
        unordered_multiset<int> result;
        for (int i : nums2)
        {
            if (auto it = lookup.find(i); it != lookup.end())
            {
                lookup.erase(it);
                result.emplace(i);
            }
        }
        return {result.begin(), result.end()};
    }
};

class LeetCodeTest : public testing::Test
{
public:
    static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<int> nums1 = {1, 2, 2, 1};
    vector<int> nums2 = {2, 2};
    vector<int> output = {2, 2};
    EXPECT_EQ(solution.intersection(nums1, nums2), output);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> nums1 = {4, 9, 5};
    vector<int> nums2 = {9, 4, 9, 8, 4};
    vector<int> output = {9, 4};
    EXPECT_EQ(solution.intersection(nums1, nums2), output);
}