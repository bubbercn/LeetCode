#pragma once
#include "Common.h"

class Solution
{
public:
    int smallestDistancePair(vector<int> &nums, int k)
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
    vector<int> nums = {1, 3, 1};
    EXPECT_EQ(solution.smallestDistancePair(nums, 1), 0);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> nums = {1, 1, 1};
    EXPECT_EQ(solution.smallestDistancePair(nums, 2), 0);
}

TEST_F(LeetCodeTest, Example3)
{
    vector<int> nums = {1, 6, 1};
    EXPECT_EQ(solution.smallestDistancePair(nums, 3), 5);
}