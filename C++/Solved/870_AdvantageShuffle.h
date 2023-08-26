#pragma once
#include "Common.h"

class Solution
{
public:
    vector<int> advantageCount(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size();
        deque<pair<int, int>> dq(n);
        for (int i = 0; i < n; i++)
        {
            dq[i].first = nums2[i];
            dq[i].second = i;
        }
        sort(dq.begin(), dq.end());
        sort(nums1.begin(), nums1.end());
        vector<int> result(n);
        for (int i = 0; i < n; i++)
        {
            if (nums1[i] > dq.front().first)
            {
                result[dq.front().second] = nums1[i];
                dq.pop_front();
            }
            else
            {
                result[dq.back().second] = nums1[i];
                dq.pop_back();
            }
        }
        return result;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<int> nums1 = {2, 7, 11, 15};
    vector<int> nums2 = {1, 10, 4, 11};
    vector<int> output = {2, 11, 7, 15};
    EXPECT_EQ(solution.advantageCount(nums1, nums2), output);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> nums1 = {12, 24, 8, 32};
    vector<int> nums2 = {13, 25, 32, 11};
    vector<int> output = {24, 32, 8, 12};
    EXPECT_EQ(solution.advantageCount(nums1, nums2), output);
}

TEST_F(LeetCodeTest, Failure1)
{
    vector<int> nums1 = {2, 0, 4, 1, 2};
    vector<int> nums2 = {1, 3, 0, 0, 2};
    vector<int> output = {2, 0, 1, 2, 4};
    EXPECT_EQ(solution.advantageCount(nums1, nums2), output);
}