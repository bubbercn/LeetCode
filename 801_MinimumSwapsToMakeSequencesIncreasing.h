#pragma once
#include "Common.h"

class Solution
{
public:
    int minSwap(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size();
        vector<vector<int>> dp(2, vector<int>(n, numeric_limits<int>::max()));
        dp[0][0] = 0;
        dp[1][0] = 1;
        for (int i = 1; i < n; i++)
        {
            if (nums1[i] > nums1[i - 1] && nums2[i] > nums2[i - 1])
            {
                dp[0][i] = dp[0][i - 1];
                dp[1][i] = dp[1][i - 1] + 1;
            }
            
            if (nums1[i] > nums2[i - 1] && nums2[i] > nums1[i - 1])
            {
                dp[0][i] = min(dp[0][i], dp[1][i - 1]);
                dp[1][i] = min(dp[1][i], dp[0][i - 1] + 1);
            }
        }
        return min(dp[0][n - 1], dp[1][n - 1]);
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