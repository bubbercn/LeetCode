#pragma once
#include "Common.h"

class Solution
{
public:
    int findMaxLength(vector<int> &nums)
    {
        replace(nums.begin(), nums.end(), 0, -1);
        vector<int> preSum(nums.size() + 1, 0);
        unordered_map<int, int> lookup = {{0, 0}};
        int result = 0;
        for (int i = 1; i < preSum.size(); i++)
        {
            preSum[i] = preSum[i - 1] + nums[i - 1];
            auto [it, inserted] = lookup.emplace(preSum[i], i);
            if (!inserted && i - it->second >= 2)
            {
                result = max(result, i - it->second);
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
    vector<int> nums = {0, 1};
    EXPECT_EQ(solution.findMaxLength(nums), 2);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> nums = {0, 1, 0};
    EXPECT_EQ(solution.findMaxLength(nums), 2);
}