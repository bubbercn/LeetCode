#pragma once
#include "Common.h"

class Solution
{
public:
    int combinationSum4(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        vector<uint64_t> dp(target + 1, 0);
        for (int i = 0; i <= target; i++)
        {
            if (i == 0)
            {
                dp[i] = 1;
            }
            else
            {
                for (auto num : nums)
                {
                    if (i - num >= 0)
                    {
                        dp[i] += dp[i - num];
                    }
                }
            }
        }
        return dp[target];
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<int> nums = {1, 2, 3};
    EXPECT_EQ(solution.combinationSum4(nums, 4), 7);
}

TEST_F(LeetCodeTest, Failure1)
{
    vector<int> nums = {3, 33, 333};
    EXPECT_EQ(solution.combinationSum4(nums, 10000), 7);
}