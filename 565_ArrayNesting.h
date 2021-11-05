#pragma once
#include "Common.h"

class Solution
{
public:
    int arrayNesting(vector<int> &nums)
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
    vector<int> nums = {5, 4, 0, 3, 1, 6, 2};
    EXPECT_EQ(solution.arrayNesting(nums), 4);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> nums = {0, 1, 2};
    EXPECT_EQ(solution.arrayNesting(nums), 1);
}