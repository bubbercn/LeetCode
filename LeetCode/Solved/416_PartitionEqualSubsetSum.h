#pragma once
#include "Common.h"

class Solution
{
public:
    bool canPartition(vector<int> &nums)
    {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if ((sum & 1) != 0)
            return false;

        int capacity = sum / 2;
        vector<int> dp(capacity, 0);

        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = capacity - 1; j >= 0; j--)
            {
                if (i == 0)
                {
                    dp[j] = nums[i] > j + 1 ? 0 : nums[i];
                }
                else
                {
                    dp[j] = max(dp[j], nums[i] + (j >= nums[i] ? dp[j - nums[i]] : 0));
                }
                if (dp[j] == capacity)
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
    vector<int> nums = {1, 5, 11, 5};
    EXPECT_EQ(solution.canPartition(nums), true);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> nums = {1, 2, 3, 5};
    EXPECT_EQ(solution.canPartition(nums), false);
}