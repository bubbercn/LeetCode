#pragma once
#include "Common.h"

class Solution
{
public:
    int numberOfArithmeticSlices(vector<int> &nums)
    {
        int result = 0;
        vector<unordered_map<long, long>> dp(nums.size());
        for (int i = 0; i < nums.size() - 1; i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (auto it = dp[i].find(static_cast<long>(nums[j]) - nums[i]); it != dp[i].end())
                {
                    result += it->second;
                    dp[j][static_cast<long>(nums[j]) - nums[i]] += it->second;
                }
                dp[j][static_cast<long>(nums[j]) - nums[i]]++;
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
    vector<int> nums = {2, 4, 6, 8, 10};
    EXPECT_EQ(solution.numberOfArithmeticSlices(nums), 7);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> nums = {7, 7, 7, 7, 7};
    EXPECT_EQ(solution.numberOfArithmeticSlices(nums), 16);
}