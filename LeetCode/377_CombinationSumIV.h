#pragma once
#include "Common.h"

class Solution
{
public:
    int combinationSum4(vector<int> &nums, int target)
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
    vector<int> nums = {1, 2, 3};
    EXPECT_EQ(solution.combinationSum4(nums, 4), 7);
}