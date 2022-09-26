#pragma once
#include "Common.h"

class Solution
{
public:
    int racecar(int target)
    {
        vector<int> dp(target + 2, 0);
        // dp[0]=0

        int k = 1;
        // S记录连续k个A指令，达到的位置
        int S = 1;
        for (int i = 1; i <= target; i++)
        {
            if (i == S)
            {
                dp[i] = k++;
                // 2^k - 1
                S = (1 << k) - 1;
            }
            else
            {
                // 情况1：连续k个A后，回退
                dp[i] = k + 1 + dp[S - i];
                // 情况2：连续k-1个A后，回退(0/1/.../k-2)步后，再前进
                for (int back = 0; back <= k - 2; back++)
                {
                    // 回退后还需前进的距离：i+S(back)-S(k-1)
                    int distance = i + (1 << back) - (1 << (k - 1));
                    dp[i] = min(dp[i], (k - 1) + 2 + back + dp[distance]);
                }
            }
        }
        return dp[target];
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    EXPECT_EQ(solution.racecar(3), 2);
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.racecar(6), 5);
}