#pragma once
#include "Common.h"

class Solution
{
public:
    bool checkSubarraySum(vector<int> &nums, int k)
    {
        int n = nums.size();
        unordered_map<int, int> sumIndexMap;
        long preSum = 0;
        sumIndexMap.emplace(0, 0);
        for (int i = 1; i <= n; i++)
        {
            preSum = (preSum + nums[i - 1]) % k;
            if (auto [it, inserted] = sumIndexMap.emplace(preSum, i); !inserted && i - it->second > 1)
                return true;
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
    vector<int> nums = {23, 2, 4, 6, 7};
    EXPECT_EQ(solution.checkSubarraySum(nums, 6), true);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> nums = {23, 2, 6, 4, 7};
    EXPECT_EQ(solution.checkSubarraySum(nums, 6), true);
}

TEST_F(LeetCodeTest, Example3)
{
    vector<int> nums = {23, 2, 6, 4, 7};
    EXPECT_EQ(solution.checkSubarraySum(nums, 13), false);
}