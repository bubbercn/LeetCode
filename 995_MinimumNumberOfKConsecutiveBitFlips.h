#pragma once
#include "Common.h"

class Solution
{
public:
    int minKBitFlips(vector<int> &nums, int k)
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
    vector<int> nums = {0, 1, 0};
    EXPECT_EQ(solution.minKBitFlips(nums, 1), 2);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> nums = {1, 1, 0};
    EXPECT_EQ(solution.minKBitFlips(nums, 2), -1);
}

TEST_F(LeetCodeTest, Example3)
{
    vector<int> nums = {0, 0, 0, 1, 0, 1, 1, 0};
    EXPECT_EQ(solution.minKBitFlips(nums, 3), 3);
}