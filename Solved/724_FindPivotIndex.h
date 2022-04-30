#pragma once
#include "Common.h"

class Solution
{
public:
    int pivotIndex(vector<int> &nums)
    {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int left = 0;
        int right = sum - nums[0];
        if (left == right)
            return 0;
        for (int i = 1; i < nums.size(); i++)
        {
            left += nums[i - 1];
            right -= nums[i];
            if (left == right)
                return i;
        }
        return -1;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<int> nums = {1, 7, 3, 6, 5, 6};
    EXPECT_EQ(solution.pivotIndex(nums), 3);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> nums = {1, 2, 3};
    EXPECT_EQ(solution.pivotIndex(nums), -1);
}

TEST_F(LeetCodeTest, Example3)
{
    vector<int> nums = {2, 1, -1};
    EXPECT_EQ(solution.pivotIndex(nums), 0);
}