#pragma once
#include "Common.h"

class Solution
{
public:
    int splitArray(vector<int> &nums, int m)
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
    vector<int> nums = {7, 2, 5, 10, 8};
    EXPECT_EQ(solution.splitArray(nums, 2), 18);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> nums = {1, 2, 3, 4, 5};
    EXPECT_EQ(solution.splitArray(nums, 2), 9);
}

TEST_F(LeetCodeTest, Example3)
{
    vector<int> nums = {1, 4, 4};
    EXPECT_EQ(solution.splitArray(nums, 3), 4);
}