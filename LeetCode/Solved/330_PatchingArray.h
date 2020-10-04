#pragma once
#include "Common.h"

class Solution
{
public:
    int minPatches(vector<int> &nums, int n)
    {
        int result = 0;
        int index = 0;
        long range = 1;
        while (range <= n)
        {
            if (index >= nums.size() || nums[index] > range)
            {
                result++;
                range += range;
            }
            else
            {
                range += nums[index];
                index++;
            }
        }

        return result;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<int> nums = {1, 3};
    EXPECT_EQ(solution.minPatches(nums, 6), 1);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> nums = {1, 5, 10};
    EXPECT_EQ(solution.minPatches(nums, 20), 2);
}

TEST_F(LeetCodeTest, Example3)
{
    vector<int> nums = {1, 2, 2};
    EXPECT_EQ(solution.minPatches(nums, 5), 0);
}

TEST_F(LeetCodeTest, Case1)
{
    vector<int> nums = {};
    EXPECT_EQ(solution.minPatches(nums, 6), 3);
}

TEST_F(LeetCodeTest, Failure1)
{
    vector<int> nums = {1, 2, 31, 33};
    EXPECT_EQ(solution.minPatches(nums, 2147483647), 28);
}