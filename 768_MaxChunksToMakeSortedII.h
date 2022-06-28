#pragma once
#include "Common.h"

class Solution
{
public:
    int maxChunksToSorted(vector<int> &arr)
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
    vector<int> arr = {5, 4, 3, 2, 1};
    EXPECT_EQ(solution.maxChunksToSorted(arr), 1);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> arr = {2, 1, 3, 4, 4};
    EXPECT_EQ(solution.maxChunksToSorted(arr), 4);
}