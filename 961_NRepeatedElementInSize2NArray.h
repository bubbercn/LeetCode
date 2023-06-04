#pragma once
#include "Common.h"

class Solution
{
public:
    int repeatedNTimes(vector<int> &nums)
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
    vector<int> nums = {1, 2, 3, 3};
    EXPECT_EQ(solution.repeatedNTimes(nums), 3);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> nums = {2, 1, 2, 5, 3, 2};
    EXPECT_EQ(solution.repeatedNTimes(nums), 2);
}

TEST_F(LeetCodeTest, Example3)
{
    vector<int> nums = {5, 1, 5, 2, 5, 3, 5, 4};
    EXPECT_EQ(solution.repeatedNTimes(nums), 5);
}