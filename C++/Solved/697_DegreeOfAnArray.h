#pragma once
#include "Common.h"

class Solution
{
public:
    int findShortestSubArray(vector<int> &nums)
    {
        struct Info
        {
            int left;
            int right;
            int count;
        };
        unordered_map<int, Info> lookup;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (!lookup.insert({nums[i], {i, i, 1}}).second)
            {
                auto &temp = lookup.at(nums[i]);
                temp.right = i;
                temp.count++;
            }
        }
        int result = 0;
        int maxFrequency = 0;
        for (const auto &[value, info] : lookup)
        {
            if (info.count > maxFrequency)
            {
                maxFrequency = info.count;
                result = info.right - info.left + 1;
            }
            else if (info.count == maxFrequency)
            {
                result = min(result, info.right - info.left + 1);
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
    vector<int> nums = {1, 2, 2, 3, 1};
    EXPECT_EQ(solution.findShortestSubArray(nums), 2);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> nums = {1, 2, 2, 3, 1, 4, 2};
    EXPECT_EQ(solution.findShortestSubArray(nums), 6);
}