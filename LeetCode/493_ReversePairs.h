#pragma once
#include "Common.h"

class Solution
{
public:
    int reversePairs(vector<int> &nums)
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
    vector<int> nums = {1, 3, 2, 3, 1};
    EXPECT_EQ(solution.reversePairs(nums), 2);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> nums = {2, 4, 3, 5, 1};
    EXPECT_EQ(solution.reversePairs(nums), 3);
}