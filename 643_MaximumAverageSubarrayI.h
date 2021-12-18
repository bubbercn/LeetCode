#pragma once
#include "Common.h"

class Solution
{
public:
    double findMaxAverage(vector<int> &nums, int k)
    {
        double result = numeric_limits<double>::lowest();
        double sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            if (i >= k)
                sum -= nums[i - k];
            if (i >= k - 1)
                result = max(result, sum / k);
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
    vector<int> nums = {1, 12, -5, -6, 50, 3};
    EXPECT_EQ(solution.findMaxAverage(nums, 4), 12.75);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> nums = {5};
    EXPECT_EQ(solution.findMaxAverage(nums, 1), 5);
}

TEST_F(LeetCodeTest, Failure1)
{
    vector<int> nums = {-1};
    EXPECT_EQ(solution.findMaxAverage(nums, 1), -1);
}