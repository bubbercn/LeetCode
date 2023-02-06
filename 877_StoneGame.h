#pragma once
#include "Common.h"

class Solution
{
public:
    bool stoneGame(vector<int> &piles)
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
    vector<int> piles = {5, 3, 4, 5};
    EXPECT_EQ(solution.stoneGame(piles), true);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> piles = {3, 7, 2, 3};
    EXPECT_EQ(solution.stoneGame(piles), true);
}