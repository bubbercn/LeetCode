#pragma once
#include "Common.h"

class Solution
{
public:
    int shortestSubarray(vector<int> &nums, int k)
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
    vector<int> nums = {1};
    EXPECT_EQ(solution.shortestSubarray(nums, 1), 1);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> nums = {1, 2};
    EXPECT_EQ(solution.shortestSubarray(nums, 4), -1);
}

TEST_F(LeetCodeTest, Example3)
{
    vector<int> nums = {2, -1, 2};
    EXPECT_EQ(solution.shortestSubarray(nums, 3), 3);
}