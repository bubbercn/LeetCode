#pragma once
#include "Common.h"

class Solution
{
public:
    bool PredictTheWinner(vector<int> &nums)
    {
        vector<int> dp = nums;
        for (int i = 1; i < dp.size(); i++)
        {
            int temp = dp.size() - i;
            for (int j = 0; j < temp; j++)
            {
                dp[j] = max(nums[j] - dp[j + 1], nums[i + j] - dp[j]);
            }
        }
        return dp[0] >= 0;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<int> nums = {1, 5, 2};
    EXPECT_EQ(solution.PredictTheWinner(nums), false);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> nums = {1, 5, 233, 7};
    EXPECT_EQ(solution.PredictTheWinner(nums), true);
}