#pragma once
#include "Common.h"

class Solution
{
public:
    int bestRotation(vector<int> &nums)
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
    vector<int> nums = {2, 3, 1, 4, 0};
    EXPECT_EQ(solution.bestRotation(nums), 3);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> nums = {1, 3, 0, 2, 4};
    EXPECT_EQ(solution.bestRotation(nums), 0);
}