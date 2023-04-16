#pragma once
#include "Common.h"

class Solution
{
public:
    int maxSubarraySumCircular(vector<int> &nums)
    {
        return 0;
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