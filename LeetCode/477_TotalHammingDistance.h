#pragma once
#include "Common.h"

class Solution
{
public:
    int totalHammingDistance(vector<int> &nums)
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
    vector<int> nums = {4, 14, 2};
    EXPECT_EQ(solution.totalHammingDistance(nums), 6);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> nums = {4, 14, 4};
    EXPECT_EQ(solution.totalHammingDistance(nums), 4);
}