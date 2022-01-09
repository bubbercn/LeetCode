#pragma once
#include "Common.h"

class Solution
{
public:
    vector<int> constructArray(int n, int k)
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
    vector<int> output = {1, 2, 3};
    EXPECT_EQ(solution.constructArray(3, 1), output);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> output = {1, 3, 2};
    EXPECT_EQ(solution.constructArray(3, 2), output);
}