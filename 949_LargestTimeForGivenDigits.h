#pragma once
#include "Common.h"

class Solution
{
public:
    string largestTimeFromDigits(vector<int> &arr)
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
    vector<int> arr = {1, 2, 3, 4};
    EXPECT_EQ(solution.largestTimeFromDigits(arr), "23:41");
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> arr = {5, 5, 5, 5};
    EXPECT_EQ(solution.largestTimeFromDigits(arr), "55:55");
}
