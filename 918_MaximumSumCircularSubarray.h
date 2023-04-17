#pragma once
#include "Common.h"

class Solution
{
public:
    int maxSubarraySumCircular(vector<int> &nums)
    {
        int totalSum = 0;
        int max = numeric_limits<int>::min();
        int curMax = 0;
        int min = numeric_limits<int>::max();
        int curMin = 0;
        for (int num : nums)
        {
            curMax = ::max(curMax + num, num);
            max = ::max(max, curMax);
            curMin = ::min(curMin + num, num);
            min = ::min(min, curMin);
            totalSum += num;
        }
        return max > 0 ? ::max(max, totalSum - min) : max;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<int> nums = {1, -2, 3, -2};
    EXPECT_EQ(solution.maxSubarraySumCircular(nums), 3);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> nums = {5, -3, 5};
    EXPECT_EQ(solution.maxSubarraySumCircular(nums), 10);
}

TEST_F(LeetCodeTest, Example3)
{
    vector<int> nums = {-3, -2, -3};
    EXPECT_EQ(solution.maxSubarraySumCircular(nums), -2);
}