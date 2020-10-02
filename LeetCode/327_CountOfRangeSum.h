#pragma once
#include "Common.h"

class Solution
{
public:
    int countRangeSum(vector<int> &nums, int lower, int upper)
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
    vector<int> nums = {-2, 5, -1};
    EXPECT_EQ(solution.countRangeSum(nums, -2, 2), 3);
}
