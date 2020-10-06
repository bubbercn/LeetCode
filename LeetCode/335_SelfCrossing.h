#pragma once
#include "Common.h"

class Solution
{
public:
    bool isSelfCrossing(vector<int> &x)
    {
        return false;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<int> input = {2, 1, 1, 2};
    EXPECT_EQ(solution.isSelfCrossing(input), true);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> input = {1, 2, 3, 4};
    EXPECT_EQ(solution.isSelfCrossing(input), false);
}

TEST_F(LeetCodeTest, Example3)
{
    vector<int> input = {1, 1, 1, 1};
    EXPECT_EQ(solution.isSelfCrossing(input), true);
}