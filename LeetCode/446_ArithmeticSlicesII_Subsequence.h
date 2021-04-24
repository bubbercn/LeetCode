#pragma once
#include "Common.h"

class Solution
{
public:
    int numberOfArithmeticSlices(vector<int> &nums)
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
    vector<int> nums = {2, 4, 6, 8, 10};
    EXPECT_EQ(solution.numberOfArithmeticSlices(nums), 7);
}
