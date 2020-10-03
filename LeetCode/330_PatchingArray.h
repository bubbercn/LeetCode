#pragma once
#include "Common.h"

class Solution
{
public:
    int minPatches(vector<int> &nums, int n)
    {
        return 0;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<int> nums = {1, 3};
    EXPECT_EQ(solution.minPatches(nums, 6), 1);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> nums = {1, 5, 10};
    EXPECT_EQ(solution.minPatches(nums, 20), 2);
}