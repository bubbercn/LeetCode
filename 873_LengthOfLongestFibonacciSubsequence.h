#pragma once
#include "Common.h"

class Solution
{
public:
    int lenLongestFibSubseq(vector<int> &arr)
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
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8};
    EXPECT_EQ(solution.lenLongestFibSubseq(arr), 5);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> arr = {1, 3, 7, 11, 12, 14, 18};
    EXPECT_EQ(solution.lenLongestFibSubseq(arr), 3);
}