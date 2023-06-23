#pragma once
#include "Common.h"

class Solution
{
public:
    int countTriplets(vector<int> &nums)
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
    vector<int> nums = {2, 1, 3};
    EXPECT_EQ(solution.countTriplets(nums), 12);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> nums = {0, 0, 0};
    EXPECT_EQ(solution.countTriplets(nums), 27);
}