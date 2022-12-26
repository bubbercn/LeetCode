#pragma once
#include "Common.h"

class Solution
{
public:
    bool isNStraightHand(vector<int> &hand, int groupSize)
    {
        if (hand.size() % groupSize != 0)
            return false;

        multiset<int> cards(hand.begin(), hand.end());
        while (!cards.empty())
        {
            int target = 0;
            for (int i = 0; i < groupSize; i++)
            {
                if (i == 0)
                {
                    target = *cards.begin();
                    cards.erase(cards.begin());
                }
                else
                {
                    target++;
                    auto it = cards.lower_bound(target);
                    if (it == cards.end() || *it != target)
                        return false;
                    cards.erase(it);
                }
            }
        }
        return true;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<int> hand = {1, 2, 3, 6, 2, 3, 4, 7, 8};
    EXPECT_EQ(solution.isNStraightHand(hand, 3), true);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> hand = {1, 2, 3, 4, 5};
    EXPECT_EQ(solution.isNStraightHand(hand, 4), false);
}

TEST_F(LeetCodeTest, Failure1)
{
    vector<int> hand = {8, 10, 12};
    EXPECT_EQ(solution.isNStraightHand(hand, 3), false);
}