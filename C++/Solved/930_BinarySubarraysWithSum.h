#pragma once
#include "Common.h"

class Solution
{
public:
    int numSubarraysWithSum(vector<int> &nums, int goal)
    {
        int n = nums.size();
        vector<int> lookup(30001);
        int sum = 0;
        int result = 0;
        lookup[0] = 1;
        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
            int target = sum - goal;
            if (target >= 0)
                result += lookup[target];
            lookup[sum]++;
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
    vector<int> nums = {1, 0, 1, 0, 1};
    EXPECT_EQ(solution.numSubarraysWithSum(nums, 2), 4);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> nums = {0, 0, 0, 0, 0};
    EXPECT_EQ(solution.numSubarraysWithSum(nums, 0), 15);
}