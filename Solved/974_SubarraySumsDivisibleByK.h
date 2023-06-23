#pragma once
#include "Common.h"

class Solution
{
public:
    int subarraysDivByK(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<int> prefixSum(n + 1);
        for (int i = 0; i < n; i++)
        {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }
        int result = 0;
        unordered_map<int, int> count;
        for (int i = 0; i <= n; i++)
        {
            int remainder = prefixSum[i] % k;
            if (remainder < 0)
                remainder += k;
            result += count[remainder];
            count[remainder]++;
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
    vector<int> nums = {4, 5, 0, -2, -3, 1};
    EXPECT_EQ(solution.subarraysDivByK(nums, 5), 7);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> nums = {5};
    EXPECT_EQ(solution.subarraysDivByK(nums, 9), 0);
}