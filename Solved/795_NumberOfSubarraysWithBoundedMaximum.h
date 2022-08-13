#pragma once
#include "Common.h"

class Solution
{
public:
    int numSubarrayBoundedMax(vector<int> &nums, int left, int right)
    {
        int result = 0;
        int count = 0;
        int begin = -1;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] < left)
            {
                result += count;
            }
            else if (nums[i] <= right)
            {
                count = i - begin;
                result += count;
            }
            else
            {
                count = 0;
                begin = i;
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
    vector<int> nums = {2, 1, 4, 3};
    EXPECT_EQ(solution.numSubarrayBoundedMax(nums, 2, 3), 3);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> nums = {2, 9, 2, 5, 6};
    EXPECT_EQ(solution.numSubarrayBoundedMax(nums, 2, 8), 7);
}

TEST_F(LeetCodeTest, Example3)
{
    vector<int> nums = {73, 55, 36, 5, 55, 14, 9, 7, 72, 52};
    EXPECT_EQ(solution.numSubarrayBoundedMax(nums, 32, 69), 22);
}