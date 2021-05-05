#pragma once
#include "Common.h"

class Solution
{
public:
    bool circularArrayLoop(vector<int> &nums)
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
    vector<int> nums = {2, -1, 1, 2, 2};
    EXPECT_EQ(solution.circularArrayLoop(nums), true);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> nums = {-1, 2};
    EXPECT_EQ(solution.circularArrayLoop(nums), false);
}

TEST_F(LeetCodeTest, Example3   )
{
    vector<int> nums = {-2, 1, -1, -2, -2};
    EXPECT_EQ(solution.circularArrayLoop(nums), false);
}
