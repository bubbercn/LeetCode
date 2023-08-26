#pragma once
#include "Common.h"

class Solution
{
public:
    int knightDialer(int n)
    {
        vector<int> dp(10, 1);
        for (int i = 2; i <= n; i++)
        {
            vector<int> next(10);
            for (int j = 0; j < 10; j++)
            {
                for (auto f : from[j])
                {
                    next[j] = (next[j] + dp[f]) % MOD;
                }
            }
            dp.swap(next);
        }
        int result = 0;
        for (auto i : dp)
        {
            result = (result + i) % MOD;
        }
        return result;
    }

private:
    inline static vector<list<int>> from = {
        {4, 6},
        {6, 8},
        {7, 9},
        {4, 8},
        {0, 3, 9},
        {},
        {0, 1, 7},
        {2, 6},
        {1, 3},
        {2, 4},
    };
    static constexpr int MOD = 1000000000 + 7;
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    EXPECT_EQ(solution.knightDialer(1), 10);
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.knightDialer(2), 20);
}

TEST_F(LeetCodeTest, Example3)
{
    EXPECT_EQ(solution.knightDialer(3131), 136006598);
}