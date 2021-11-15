#pragma once
#include "Common.h"

class Solution
{
public:
    int findUnsortedSubarray(vector<int> &nums)
    {
        int max = nums[0];
        int end = -1;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] >= max)
            {
                max = nums[i];
            }
            else
            {
                end = i;
            }
        }

        int min = nums[nums.size() - 1];
        int begin = 0;
        for (int i = nums.size() - 2; i >= 0; i--)
        {
            if (nums[i] <= min)
            {
                min = nums[i];
            }
            else
            {
                begin = i;
            }
        }

        return end - begin + 1;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<int> nums = {2,6,4,8,10,9,15};
    EXPECT_EQ(solution.findUnsortedSubarray(nums), 5);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> nums = {1,2,3,4};
    EXPECT_EQ(solution.findUnsortedSubarray(nums), 0);
}

TEST_F(LeetCodeTest, Example3)
{
    vector<int> nums = {1};
    EXPECT_EQ(solution.findUnsortedSubarray(nums), 0);
}