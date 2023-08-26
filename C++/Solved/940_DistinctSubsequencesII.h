#pragma once
#include "Common.h"

class Solution
{
public:
    int distinctSubseqII(string_view s)
    {
        int n = s.length();
        vector<long> dp(26);
        for (int i = 0; i < n; i++)
        {
            int index = s[i] - 'a';
            dp[index]++;
            for (int j = 0; j < 26; j++)
            {
                if (j != index)
                    dp[index] += dp[j];
            }
            dp[index] %= MOD;
        }
        return accumulate(dp.begin(), dp.end(), 0l) % MOD;
    }

private:
    static constexpr int MOD = 1000000000 + 7;
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    EXPECT_EQ(solution.distinctSubseqII("abc"), 7);
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.distinctSubseqII("aba"), 6);
}

TEST_F(LeetCodeTest, Example3)
{
    EXPECT_EQ(solution.distinctSubseqII("aaa"), 3);
}
