#pragma once
#include "Common.h"

class Solution
{
public:
    bool splitArraySameAverage(vector<int> &nums)
    {
        return false;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<int> nums = {1,2,3,4,5,6,7,8};
    EXPECT_EQ(solution.splitArraySameAverage(nums), true);
}