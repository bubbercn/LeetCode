#pragma once
#include "Common.h"

class Solution
{
public:
    int countArrangement(int n)
    {
        int size = 1 << n;
        vector<int> dp(size);
        dp[0] = 1;
        for (int state = 1; state < size; state++)
        {
            bitset<15> mask(state);
            int num = mask.count();
            for (int i = 0; i < n; i++)
            {
                if (state & (1 << i) && (num % (i + 1) == 0 || (i + 1) % num == 0))
                {
                    dp[state] += dp[state ^ (1 << i)];
                }
            }
        }
        return dp[size - 1];
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    EXPECT_EQ(solution.countArrangement(2), 2);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> nums = {0, 1, 0};
    EXPECT_EQ(solution.countArrangement(1), 1);
}