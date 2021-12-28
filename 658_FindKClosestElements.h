#pragma once
#include "Common.h"

class Solution
{
public:
    vector<int> findClosestElements(vector<int> &arr, int k, int x)
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
    vector<int> arr = {1, 2, 3, 4, 5};
    vector<int> output = {1, 2, 3, 4};
    EXPECT_EQ(solution.findClosestElements(arr, 4, 3), output);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> arr = {1, 2, 3, 4, 5};
    vector<int> output = {1, 2, 3, 4};
    EXPECT_EQ(solution.findClosestElements(arr, 4, -1), output);
}