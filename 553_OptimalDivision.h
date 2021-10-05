#pragma once
#include "Common.h"

class Solution
{
public:
    string optimalDivision(vector<int> &nums)
    {
        return {};
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<int> nums = {1000, 100, 10, 2};
    EXPECT_EQ(solution.optimalDivision(nums), "1000/(100/10/2)");
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> nums = {2, 3, 4};
    EXPECT_EQ(solution.optimalDivision(nums), "2/(3/4)");
}

TEST_F(LeetCodeTest, Example3)
{
    vector<int> nums = {2};
    EXPECT_EQ(solution.optimalDivision(nums), "2");
}