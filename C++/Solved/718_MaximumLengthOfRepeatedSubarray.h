#pragma once
#include "Common.h"

class Solution
{
public:
    int findLength(vector<int> &nums1, vector<int> &nums2)
    {
        int m = nums1.size();
        int n = nums2.size();
        int result = 0;
        vector<int> dp(n, 0);
        for (int i = 0; i < m; i++)
        {
            for (int j = n - 1; j >= 0; j--)
            {
                if (i == 0 || j == 0)
                {
                    dp[j] = nums1[i] == nums2[j] ? 1 : 0;
                    result = max(dp[j], result);
                }
                else if (nums1[i] == nums2[j])
                {
                    dp[j] = dp[j - 1] + 1;
                    result = max(dp[j], result);
                }
                else
                {
                    dp[j] = 0;
                }
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

TEST_F(LeetCodeTest, Failure1)
{
    vector<int> nums1 = {1, 0, 0, 0, 1, 0, 0, 1, 0, 0};
    vector<int> nums2 = {0, 1, 1, 1, 0, 1, 1, 1, 0, 0};
    EXPECT_EQ(solution.findLength(nums1, nums2), 3);
}
