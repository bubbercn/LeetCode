#pragma once
#include "Common.h"

class Solution
{
public:
    int maxTurbulenceSize(vector<int> &arr)
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
    vector<int> arr = {9, 4, 2, 10, 7, 8, 8, 1, 9};
    EXPECT_EQ(solution.maxTurbulenceSize(arr), 5);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> arr = {4, 8, 12, 16};
    EXPECT_EQ(solution.maxTurbulenceSize(arr), 2);
}

TEST_F(LeetCodeTest, Example3)
{
    vector<int> arr = {100};
    EXPECT_EQ(solution.maxTurbulenceSize(arr), 1);
}