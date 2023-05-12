#pragma once
#include "Common.h"

class Solution
{
public:
    vector<int> beautifulArray(int n)
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
    vector<int> output = {2, 1, 4, 3};
    EXPECT_EQ(solution.beautifulArray(4), output);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> output = {3, 1, 2, 5, 4};
    EXPECT_EQ(solution.beautifulArray(5), output);
}
