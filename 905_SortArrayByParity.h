#pragma once
#include "Common.h"

class Solution
{
public:
    vector<int> sortArrayByParity(vector<int> &nums)
    {
        int n = nums.size();
        int left = 0;
        int right = n - 1;
        while (left < right)
        {
            while (left < n && (nums[left] & 1) == 0)
            {
                left++;
            }
            while (right >= 0 && (nums[right] & 1) == 1)
            {
                right--;
            }
            if (left < right)
            {
                swap(nums[left], nums[right]);
                left++;
                right--;
            }
        }
        return nums;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<int> nums = {3, 1, 2, 4};
    vector<int> output = {4, 2, 1, 3};
    EXPECT_EQ(solution.sortArrayByParity(nums), output);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> nums = {0};
    vector<int> output = {0};
    EXPECT_EQ(solution.sortArrayByParity(nums), output);
}

TEST_F(LeetCodeTest, Failure1)
{
    vector<int> nums = {0, 2};
    vector<int> output = {0, 2};
    EXPECT_EQ(solution.sortArrayByParity(nums), output);
}
