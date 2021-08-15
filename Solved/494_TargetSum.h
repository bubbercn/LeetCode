#pragma once
#include "Common.h"

class Solution
{
public:
    int findTargetSumWays(vector<int> &nums, int target)
    {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (target > sum || target < -sum)
            return 0;

        if ((sum + target) % 2 != 0)
            return 0;

        int x = (sum + target) / 2;
        vector<int> dp(x + 1, 0);
        dp[0] = 1;
        for (auto num : nums)
        {
            for (int i = x; i >= num; i--)
            {
                dp[i] = dp[i - num] + dp[i];
            }
        }
        return dp[x];
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<int> nums = {1, 1, 1, 1, 1};
    EXPECT_EQ(solution.findTargetSumWays(nums, 3), 5);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> nums = {1};
    EXPECT_EQ(solution.findTargetSumWays(nums, 1), 1);
}

TEST_F(LeetCodeTest, Failure1)
{
    vector<int> nums = {1, 0};
    EXPECT_EQ(solution.findTargetSumWays(nums, 1), 2);
}

TEST_F(LeetCodeTest, Failure2)
{
    vector<int> nums = {20, 48, 33, 16, 19, 44, 14, 31, 42, 34, 38, 32, 27, 7, 22, 22, 48, 18, 48, 39};
    EXPECT_EQ(solution.findTargetSumWays(nums, 1), 0);
}