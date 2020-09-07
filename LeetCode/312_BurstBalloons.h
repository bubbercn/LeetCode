#pragma once
#include "Common.h"

class Solution
{
public:
    int maxCoins(vector<int> &nums)
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
    vector<int> nums = {3, 1, 5, 8};
    EXPECT_EQ(solution.maxCoins(nums), 167);
}
