#pragma once
#include "Common.h"

class Solution
{
public:
    vector<int> countBits(int num)
    {
        return {};
    }
};

class LeetCodeTest : public testing::Test
{
public:
    static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<int> output = {0, 1, 1};
    EXPECT_EQ(solution.countBits(2), output);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> output = {0, 1, 1, 2, 1, 2};
    EXPECT_EQ(solution.countBits(5), output);
}