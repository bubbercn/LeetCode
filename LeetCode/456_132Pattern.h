#pragma once
#include "Common.h"

class Solution
{
public:
    bool find132pattern(vector<int> &nums)
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
    vector<int> nums = {1, 2, 3, 4};
    EXPECT_EQ(solution.find132pattern(nums), false);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> nums = {3, 1, 4, 2};
    EXPECT_EQ(solution.find132pattern(nums), false);
}

TEST_F(LeetCodeTest, Example3)
{
    vector<int> nums = {-1, 3, 2, 0};
    EXPECT_EQ(solution.find132pattern(nums), true);
}
