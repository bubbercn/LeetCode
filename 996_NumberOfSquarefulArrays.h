#pragma once
#include "Common.h"

class Solution
{
public:
    int numSquarefulPerms(vector<int> &nums)
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
    vector<int> nums = {1, 17, 8};
    EXPECT_EQ(solution.numSquarefulPerms(nums), 2);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> nums = {2, 2, 2};
    EXPECT_EQ(solution.numSquarefulPerms(nums), 1);
}
