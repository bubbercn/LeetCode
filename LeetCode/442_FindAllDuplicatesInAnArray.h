#pragma once
#include "Common.h"

class Solution
{
public:
    vector<int> findDuplicates(vector<int> &nums)
    {
        vector<int> result;
        for (auto num : nums)
        {
            int temp = abs(num);
            if (nums[temp - 1] < 0)
            {
                result.emplace_back(temp);
            }
            else
            {
                nums[temp - 1] = - nums[temp - 1];
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
    vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};
    vector<int> output = {2, 3};
    EXPECT_EQ(solution.findDuplicates(nums), output);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> nums = {1, 1, 2};
    vector<int> output = {1};
    EXPECT_EQ(solution.findDuplicates(nums), output);
}

TEST_F(LeetCodeTest, Example3)
{
    vector<int> nums = {1};
    vector<int> output = {};
    EXPECT_EQ(solution.findDuplicates(nums), output);
}