#pragma once
#include "Common.h"

class Solution
{
public:
    int longestMountain(vector<int> &arr)
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
    vector<int> arr = {2, 1, 4, 7, 3, 2, 5};
    EXPECT_EQ(solution.longestMountain(arr), 5);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> arr = {2, 2, 2};
    EXPECT_EQ(solution.longestMountain(arr), 0);
}