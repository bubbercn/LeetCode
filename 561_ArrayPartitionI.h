#pragma once
#include "Common.h"

class Solution
{
public:
    int arrayPairSum(vector<int> &nums)
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
    vector<int> nums = {1, 4, 3, 2};
    EXPECT_EQ(solution.arrayPairSum(nums), 4);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> nums = {6, 2, 6, 5, 1, 2};
    EXPECT_EQ(solution.arrayPairSum(nums), 9);
}