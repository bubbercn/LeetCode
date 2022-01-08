#pragma once
#include "Common.h"

class Solution
{
public:
    bool checkPossibility(vector<int> &nums)
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
    vector<int> nums = {4, 2, 3};
    EXPECT_EQ(solution.checkPossibility(nums), true);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> nums = {4, 2, 1};
    EXPECT_EQ(solution.checkPossibility(nums), false);
}