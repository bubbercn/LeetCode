#pragma once
#include "Common.h"

class Solution
{
public:
    int splitArray(vector<int> &nums, int m)
    {
        long left = numeric_limits<long>::min();
        long right = 0;

        for (auto i : nums)
        {
            left = max(left, static_cast<long>(i));
            right += i;
        }

        while (left < right)
        {
            long middle = (left + right) / 2;
            int n = helper(nums, m, middle);
            if (n > m)
            {
                left = middle + 1;
            }
            else
            {
                right = middle;
            }
        }

        return left;
    }
private: 
    int helper(const vector<int>& nums, int m, int max)
    {
        int result = 0;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            if (sum > max)
            {
                result++;
                sum = nums[i];
            }
        }
        if (!nums.empty())
            result++;
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
    vector<int> nums = {7, 2, 5, 10, 8};
    EXPECT_EQ(solution.splitArray(nums, 2), 18);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> nums = {1, 2, 3, 4, 5};
    EXPECT_EQ(solution.splitArray(nums, 2), 9);
}

TEST_F(LeetCodeTest, Example3)
{
    vector<int> nums = {1, 4, 4};
    EXPECT_EQ(solution.splitArray(nums, 3), 4);
}