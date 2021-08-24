#pragma once
#include "Common.h"

class Solution
{
public:
    int change(int amount, vector<int> &coins)
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
    vector<int> coins = {1, 2, 5};
    EXPECT_EQ(solution.change(5, coins), 4);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> coins = {2};
    EXPECT_EQ(solution.change(3, coins), 0);
}

TEST_F(LeetCodeTest, Example3)
{
    vector<int> coins = {10};
    EXPECT_EQ(solution.change(10, coins), 1);
}