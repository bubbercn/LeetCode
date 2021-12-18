#pragma once
#include "Common.h"

class Solution
{
public:
    vector<int> findErrorNums(vector<int> &nums)
    {
        int duplicate;
        int missing;
        for (int i = 0; i < nums.size(); i++)
        {
            int targetIndex = abs(nums[i]) - 1;
            if (nums[targetIndex] > 0)
            {
                nums[targetIndex] *= -1;
            }
            else
            {
                duplicate = targetIndex + 1;
            }
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > 0)
            {
                missing = i + 1;
                break;
            }
        }
        return {duplicate, missing};
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<int> nums = {1, 2, 2, 4};
    vector<int> output = {2, 3};
    EXPECT_EQ(solution.findErrorNums(nums), output);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> nums = {1, 1};
    vector<int> output = {1, 2};
    EXPECT_EQ(solution.findErrorNums(nums), output);
}