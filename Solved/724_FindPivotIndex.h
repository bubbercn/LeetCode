#pragma once
#include "Common.h"

class Solution
{
public:
    int pivotIndex(vector<int> &nums)
    {
        int leftSum = 0;
        int rightSum = accumulate(nums.begin(), nums.end(), 0);
        for (int i = 0; i < nums.size(); i++)
        {
            rightSum -= nums[i];
            if (leftSum == rightSum)
                return i;
            leftSum += nums[i];
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