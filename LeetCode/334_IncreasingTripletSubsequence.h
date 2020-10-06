#pragma once
#include "Common.h"

class Solution
{
public:
    bool increasingTriplet(vector<int> &nums)
    {
        return false;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<int> nums = {1, 2, 3, 4, 5};
    EXPECT_EQ(solution.increasingTriplet(nums), true);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> nums = {5, 4, 3, 2, 1};
    EXPECT_EQ(solution.increasingTriplet(nums), false);
}