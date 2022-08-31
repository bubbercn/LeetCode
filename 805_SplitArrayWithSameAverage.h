#pragma once
#include "Common.h"

class Solution
{
public:
    bool splitArraySameAverage(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
            return false;
        int sum = accumulate(nums.begin(), nums.end(), 0);
        double avg = static_cast<double>(sum) / n;
        vector<double> nums1((n + 1) / 2, 0);
        vector<double> nums2(n - nums1.size(), 0);
        for (int i = 0; i < n; i++)
        {
            if (i < nums1.size())
            {
                nums1[i] = nums[i] - avg;
                if (nums1[i] == 0)
                    return true;
            }
            else
            {
                nums2[i - nums1.size()] = nums[i] - avg;
                if (nums2[i] == 0)
                    return true;
            }
        }
        
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
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8};
    EXPECT_EQ(solution.splitArraySameAverage(nums), true);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> nums = {3, 1};
    EXPECT_EQ(solution.splitArraySameAverage(nums), false);
}