#pragma once
#include "Common.h"

class Solution
{
public:
    int maximumProduct(vector<int> &nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        if (nums[0] >= 0 || nums[1] >= 0)
            return nums[n - 1] * nums[n - 2] * nums[n - 3];
        
        return max(nums[0] * nums[1] * nums[n - 1], nums[n - 1] * nums[n - 2] * nums[n - 3]);
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
    EXPECT_EQ(solution.maximumProduct(nums), 6);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> nums = {1, 2, 3, 4};
    EXPECT_EQ(solution.maximumProduct(nums), 24);
}

TEST_F(LeetCodeTest, Example3)
{
    vector<int> nums = {-1, -2, -3};
    EXPECT_EQ(solution.maximumProduct(nums), -6);
}