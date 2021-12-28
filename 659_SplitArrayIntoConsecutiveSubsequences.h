#pragma once
#include "Common.h"

class Solution
{
public:
    bool isPossible(vector<int> &nums)
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
    vector<int> nums = {1, 2, 3, 3, 4, 5};
    EXPECT_EQ(solution.isPossible(nums), true);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> nums = {1, 2, 3, 3, 4, 4, 5, 5};
    EXPECT_EQ(solution.isPossible(nums), true);
}

TEST_F(LeetCodeTest, Example3)
{
    vector<int> nums = {1, 2, 3, 4, 4, 5};
    EXPECT_EQ(solution.isPossible(nums), false;);
}