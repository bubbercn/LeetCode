#pragma once
#include "Common.h"

class Solution
{
public:
    int findNumberOfLIS(vector<int> &nums)
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
    vector<int> nums = {1, 3, 5, 4, 7};
    EXPECT_EQ(solution.findNumberOfLIS(nums), 2);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> nums = {2, 2, 2, 2, 2};
    EXPECT_EQ(solution.findNumberOfLIS(nums), 5);
}
