#pragma once
#include "Common.h"

class Solution
{
public:
    int deleteAndEarn(vector<int> &nums)
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
    vector<int> nums = {3, 4, 2};
    EXPECT_EQ(solution.deleteAndEarn(nums), 6);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> nums = {2, 2, 3, 3, 3, 4};
    EXPECT_EQ(solution.deleteAndEarn(nums), 9);
}
