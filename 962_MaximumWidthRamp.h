#pragma once
#include "Common.h"

class Solution
{
public:
    int maxWidthRamp(vector<int> &nums)
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
    vector<int> nums = {6, 0, 8, 2, 1, 5};
    EXPECT_EQ(solution.maxWidthRamp(nums), 4);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> nums = {9, 8, 1, 0, 1, 9, 4, 0, 4, 1};
    EXPECT_EQ(solution.maxWidthRamp(nums), 7);
}
