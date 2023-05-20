#pragma once
#include "Common.h"

class Solution
{
public:
    bool validMountainArray(vector<int> &arr)
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
    vector<int> arr = {2, 1};
    EXPECT_EQ(solution.validMountainArray(arr), false);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> arr = {3, 5, 5};
    EXPECT_EQ(solution.validMountainArray(arr), false);
}

TEST_F(LeetCodeTest, Example3)
{
    vector<int> arr = {0, 3, 2, 1};
    EXPECT_EQ(solution.validMountainArray(arr), true);
}