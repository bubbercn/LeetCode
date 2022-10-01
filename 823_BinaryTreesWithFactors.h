#pragma once
#include "Common.h"

class Solution
{
public:
    int numFactoredBinaryTrees(vector<int> &arr)
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
    vector<int> arr = {2, 4};
    EXPECT_EQ(solution.numFactoredBinaryTrees(arr), 3);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> arr = {2, 4, 5, 10};
    EXPECT_EQ(solution.numFactoredBinaryTrees(arr), 7);
}