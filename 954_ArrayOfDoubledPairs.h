#pragma once
#include "Common.h"

class Solution
{
public:
    bool canReorderDoubled(vector<int> &arr)
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
    vector<int> arr = {3, 1, 3, 6};
    EXPECT_EQ(solution.canReorderDoubled(arr), false);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> arr = {2, 1, 2, 6};
    EXPECT_EQ(solution.canReorderDoubled(arr), false);
}

TEST_F(LeetCodeTest, Example3)
{
    vector<int> arr = {4, -2, 2, -4};
    EXPECT_EQ(solution.canReorderDoubled(arr), true);
}