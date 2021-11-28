#pragma once
#include "Common.h"

class Solution
{
public:
    int triangleNumber(vector<int> &nums)
    {
        int result = 0;
        sort(nums.begin(), nums.end());
        vector<vector<int>> lookup(nums.size());
        for (int i = 1; i < nums.size() - 1; i++)
        {
            for (int j = 0; j < i; j++)
            {
                lookup[i].emplace_back(nums[j] + nums[i]);
            }
        }
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            for (int j = 1; j < i; j++)
            {
                auto it = upper_bound(lookup[j].begin(), lookup[j].end(), nums[i]);
                result += distance(it, lookup[j].end());
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
    vector<int> nums = {2, 2, 3, 4};
    EXPECT_EQ(solution.triangleNumber(nums), 3);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> nums = {4, 2, 3, 4};
    EXPECT_EQ(solution.triangleNumber(nums), 4);
}