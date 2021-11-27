#pragma once
#include "Common.h"

class Solution
{
public:
    int triangleNumber(vector<int> &nums)
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
    vector<int> nums = {2, 2, 3, 4};
    EXPECT_EQ(solution.triangleNumber(nums), 2);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> nums = {4, 2, 3, 4};
    EXPECT_EQ(solution.triangleNumber(nums), 4);
}