#pragma once
#include "Common.h"

class Solution
{
public:
    int findNumberOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        int maxLength = 0;
        int result = 0;
        vector<int> dp(n, 1);
        vector<int> count(n, 1);
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                if (nums[i] > nums[j])
                {
                    if (dp[j] + 1 > dp[i])
                    {
                        dp[i] = dp[j] + 1;
                        count[i] = count[j];
                    }
                    else if (dp[j] + 1 == dp[i])
                    {
                        count[i] += count[j];
                    }
                }
            }
            if (dp[i] > maxLength)
            {
                maxLength = dp[i];
                result = count[i];
            }
            else if (dp[i] == maxLength)
            {
                result += count[i];
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
    vector<int> nums = {1, 3, 5, 4, 7};
    EXPECT_EQ(solution.findNumberOfLIS(nums), 2);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> nums = {2, 2, 2, 2, 2};
    EXPECT_EQ(solution.findNumberOfLIS(nums), 5);
}
