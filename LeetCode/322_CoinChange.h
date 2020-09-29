#pragma once
#include "Common.h"

class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        return 0;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<int> coins = {1, 2, 5};
    EXPECT_EQ(solution.coinChange(coins, 11), 3);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> coins = {2};
    EXPECT_EQ(solution.coinChange(coins, 3), -1);
}

TEST_F(LeetCodeTest, Example3)
{
    vector<int> coins = {1};
    EXPECT_EQ(solution.coinChange(coins, 0), 0);
}

TEST_F(LeetCodeTest, Example4)
{
    vector<int> coins = {1};
    EXPECT_EQ(solution.coinChange(coins, 1), 1);
}

TEST_F(LeetCodeTest, Example5)
{
    vector<int> coins = {1};
    EXPECT_EQ(solution.coinChange(coins, 2), 2);
}
