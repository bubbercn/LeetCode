#pragma once
#include "Common.h"

class Solution
{
public:
    vector<int> deckRevealedIncreasing(vector<int> &deck)
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
    vector<int> deck = {17, 13, 11, 2, 3, 5, 7};
    vector<int> output = {2, 13, 3, 11, 5, 17, 7};
    EXPECT_EQ(solution.deckRevealedIncreasing(deck), output);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> deck = {1, 1000};
    vector<int> output = {1, 1000};
    EXPECT_EQ(solution.deckRevealedIncreasing(deck), output);
}