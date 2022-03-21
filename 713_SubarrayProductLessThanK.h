#pragma once
#include "Common.h"

class Solution
{
public:
    int numSubarrayProductLessThanK(vector<int> &nums, int k)
    {
        int result = 0;
        int product = nums[0];
        int left = 0;
        int right = 1;
        int n = nums.size();
        while (true)
        {
            if (product < k)
            {
                result++;
                if (right < n)
                {
                    product *= nums[right++];
                    continue;
                }
            }

            product /= nums[left++];
            if (left == n)
                break;
            if (left == right)
            {
                product = nums[left];
                right = left + 1;
            }
            result += right - left - 1;
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
    vector<int> nums = {10, 5, 2, 6};
    EXPECT_EQ(solution.numSubarrayProductLessThanK(nums, 100), 8);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> nums = {1, 2, 3};
    EXPECT_EQ(solution.numSubarrayProductLessThanK(nums, 0), 0);
}