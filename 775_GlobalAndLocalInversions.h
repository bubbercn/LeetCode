#pragma once
#include "Common.h"

class Solution
{
public:
    bool isIdealPermutation(vector<int> &nums)
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
    vector<int> nums = {1, 0, 2};
    EXPECT_EQ(solution.isIdealPermutation(nums), true);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> nums = {1, 2, 0};
    EXPECT_EQ(solution.isIdealPermutation(nums), false);
}