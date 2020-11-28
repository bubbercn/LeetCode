#pragma once
#include "Common.h"

class Solution
{
public:
    int wiggleMaxLength(vector<int> &nums)
    {
        return 0;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<int> nums = {1, 7, 4, 9, 2, 5};
    EXPECT_EQ(solution.wiggleMaxLength(nums), 6);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> nums = {1, 17, 5, 10, 13, 15, 10, 5, 16, 8};
    EXPECT_EQ(solution.wiggleMaxLength(nums), 7);
}

TEST_F(LeetCodeTest, Example3)
{
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    EXPECT_EQ(solution.wiggleMaxLength(nums), 2);
}
