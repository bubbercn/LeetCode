#pragma once
#include "Common.h"

class Solution
{
public:
    int maxCoins(vector<int> &nums)
    {
        if (nums.empty())
            return 0;
        
        nums.insert(nums.begin(), 1);
        nums.emplace_back(1);

        vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), 0));

        for (int length = 0; length < nums.size(); length++)
        {
            for (int i = 0; i + length < nums.size(); i++)
            {
                if (length == 0)
                {
                    dp[i][i] = 0;
                }
                else
                {
                    dp[i][i + length] = helper(dp, i, length, nums);
                }
            }
        }
        return dp[0][nums.size() - 1];
    }

private:
    int helper(const vector<vector<int>> &dp, int i, int length, const vector<int> &nums)
    {
        int max = 0;
        for (int k = i + 1; k < i + length; k++)
        {
            int score = dp[i][k] + nums[i] * nums[k] * nums[i + length] + dp[k][i + length];
            max = ::max(max, score);
        }
        return max;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<int> nums = {3, 1, 5, 8};
    EXPECT_EQ(solution.maxCoins(nums), 167);
}
