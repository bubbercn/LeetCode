#pragma once
#include "Common.h"

class Solution
{
public:
    bool PredictTheWinner(vector<int> &nums)
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
    vector<int> nums = {1, 5, 2};
    EXPECT_EQ(solution.PredictTheWinner(nums), false);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> nums = {1, 5, 233, 7};
    EXPECT_EQ(solution.PredictTheWinner(nums), true);
}