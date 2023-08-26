#pragma once
#include "Common.h"

class Solution
{
public:
    vector<int> deckRevealedIncreasing(vector<int> &deck)
    {
        int n = deck.size();
        sort(deck.begin(), deck.end(), greater<int>());
        list<int> l(deck.begin(), deck.end());
        list<int> result;
        for (auto it = l.begin(); it != l.end(); it++)
        {
            if (!result.empty())
            {
                int temp = result.back();
                result.pop_back();
                result.push_front(temp);
            }
            result.push_front(*it);
        }
        return {result.begin(), result.end()};
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