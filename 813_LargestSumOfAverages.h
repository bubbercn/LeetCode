#pragma once
#include "Common.h"

class Solution
{
public:
    double largestSumOfAverages(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<double> sum(n, 0);
        sum[0] = nums[0];
        for (int i = 1; i < n; i++)
        {
            sum[i] = sum[i - 1] + nums[i];
        }
        vector<vector<double>> dp(n + 1, vector<double>(k + 1, 0));
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= k && j <= i; j++)
            {
                if (i == 1)
                {
                    dp[i][j] = nums[0];
                }
                else if (j == 1)
                {
                    dp[i][j] = sum[i - 1] / i;
                }
                else
                {
                    for (int k = 1; k < i ; k++)
                    {
                        dp[i][j] = max(dp[i][j], dp[k][j - 1] + (sum[i - 1] - sum[k - 1]) / (i - k));
                    }
                }
            }
        }
        return dp[n][k];
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<int> nums = {9, 1, 2, 3, 9};
    EXPECT_EQ(solution.largestSumOfAverages(nums, 3), 20);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    EXPECT_EQ(solution.largestSumOfAverages(nums, 4), 20.5);
}