#pragma once
#include "Common.h"

class Solution
{
public:
    bool xorGame(vector<int> &nums)
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
    vector<int> nums = {1, 1, 2};
    EXPECT_EQ(solution.xorGame(nums), false);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> nums = {0, 1};
    EXPECT_EQ(solution.xorGame(nums), true);
}

TEST_F(LeetCodeTest, Example3)
{
    vector<int> nums = {1, 2, 3};
    EXPECT_EQ(solution.xorGame(nums), true);
}