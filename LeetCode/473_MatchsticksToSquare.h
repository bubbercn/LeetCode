#pragma once
#include "Common.h"

class Solution
{
public:
    bool makesquare(vector<int> &matchsticks)
    {
        return false;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<int> matchsticks = {1, 1, 2, 2, 2};
    EXPECT_EQ(solution.makesquare(matchsticks), true);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> matchsticks = {3, 3, 3, 3, 4};
    EXPECT_EQ(solution.makesquare(matchsticks), false);
}