#pragma once
#include "Common.h"

class Solution
{
public:
    vector<int> findDisappearedNumbers(vector<int> &nums)
    {
        vector<int> result;
        for (int i = 0; i < nums.size(); i++)
        {
            while (nums[nums[i] - 1] != nums[i])
            {
                swap(nums[nums[i] - 1], nums[i]);
            }
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != i + 1)
            {
                result.emplace_back(i + 1);
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
    vector<int> output = {5, 6};
    EXPECT_EQ(solution.findDisappearedNumbers(nums), output);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> nums = {1, 1};
    vector<int> output = {2};
    EXPECT_EQ(solution.findDisappearedNumbers(nums), output);
}