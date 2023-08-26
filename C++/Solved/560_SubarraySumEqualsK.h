#pragma once
#include "Common.h"

class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        unordered_map<int, int> sumLookup{{0, 1}};
        int result = 0;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            if (auto it = sumLookup.find(sum - k); it != sumLookup.end())
            {
                result += it->second;
            }
            sumLookup[sum]++;
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
    vector<int> nums = {1, 1, 1};
    EXPECT_EQ(solution.subarraySum(nums, 2), 2);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> nums = {1, 2, 3};
    EXPECT_EQ(solution.subarraySum(nums, 3), 2);
}

TEST_F(LeetCodeTest, Failure1)
{
    vector<int> nums = {-1, -1, 1};
    EXPECT_EQ(solution.subarraySum(nums, 0), 1);
}