#pragma once
#include "Common.h"

class Solution
{
public:
    int findMaxLength(vector<int> &nums)
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
    vector<int> nums = {0, 1};
    EXPECT_EQ(solution.findMaxLength(nums), 2);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> nums = {0, 1, 0};
    EXPECT_EQ(solution.findMaxLength(nums), 2);
}