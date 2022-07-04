#pragma once
#include "Common.h"

class Solution
{
public:
    bool isIdealPermutation(vector<int> &nums)
    {
        int n = nums.size();
        if (n <= 2)
            return true;
        int min = nums[n - 1];
        for (int i = n - 3; i >= 0; i--)
        {
            if (nums[i] > min)
                return false;
            min = ::min(min, nums[i + 1]);
        }
        return true;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<int> nums = {1, 0, 2};
    EXPECT_EQ(solution.isIdealPermutation(nums), true);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> nums = {1, 2, 0};
    EXPECT_EQ(solution.isIdealPermutation(nums), false);
}