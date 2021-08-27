#pragma once
#include "Common.h"

class Solution
{
public:
    int change(int amount, vector<int> &coins)
    {
        vector<int> result(amount + 1, 0);
        result[0] = 1;
        for (auto coin : coins)
        {
            for (int i = coin; i <= amount; i++)
            {
                result[i] += result[i - coin];
            }
        }
        return result[amount];
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

TEST_F(LeetCodeTest, Failure1)
{
    vector<int> coins = {7};
    EXPECT_EQ(solution.change(0, coins), 1);
}

TEST_F(LeetCodeTest, Failure2)
{
    vector<int> coins = {3, 5, 7, 8, 9, 10, 11};
    EXPECT_EQ(solution.change(500, coins), 35502874);
}