#pragma once
#include "Common.h"

class Solution
{
public:
    int largestComponentSize(vector<int> &nums)
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
    vector<int> nums = {4, 6, 15, 35};
    EXPECT_EQ(solution.largestComponentSize(nums), 4);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> nums = {20, 50, 9, 63};
    EXPECT_EQ(solution.largestComponentSize(nums), 2);
}

TEST_F(LeetCodeTest, Example3)
{
    vector<int> nums = {2, 3, 6, 7, 4, 12, 21, 39};
    EXPECT_EQ(solution.largestComponentSize(nums), 8);
}