#pragma once
#include "Common.h"

class Solution
{
public:
    int minEatingSpeed(vector<int> &piles, int h)
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
    vector<int> piles = {3, 6, 7, 11};
    EXPECT_EQ(solution.minEatingSpeed(piles, 8), 4);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> piles = {30, 11, 23, 4, 20};
    EXPECT_EQ(solution.minEatingSpeed(piles, 5), 30);
}

TEST_F(LeetCodeTest, Example3)
{
    vector<int> piles = {30, 11, 23, 4, 20};
    EXPECT_EQ(solution.minEatingSpeed(piles, 6), 23);
}