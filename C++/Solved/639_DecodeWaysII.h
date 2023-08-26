#pragma once
#include "Common.h"

class Solution
{
public:
    int numDecodings(string_view s)
    {
        int n = s.length();
        vector<int> dp(n + 1, 0);
        dp[n] = 1;
        auto case1 = [&](int i) -> long
        {
            if (s[i] == '0')
            {
                return 0;
            }
            else if (s[i] == '*')
            {

                return 9l * dp[i + 1];
            }
            else
            {
                return dp[i + 1];
            }
        };
        auto case2 = [&](int i) -> long
        {
            if (i + 1 >= n)
                return 0;

            if (s[i] == '*')
            {
                if (s[i + 1] == '*')
                {
                    return 15l * dp[i + 2];
                }
                else if (s[i + 1] >= '0' && s[i + 1] <= '6')
                {
                    return 2l * dp[i + 2];
                }
                else
                {
                    return dp[i + 2];
                }
            }
            else if (s[i] == '1')
            {
                if (s[i + 1] == '*')
                {
                    return 9l * dp[i + 2];
                }
                else
                {
                    return dp[i + 2];
                }
            }
            else if (s[i] == '2')
            {
                if (s[i + 1] == '*')
                {
                    return 6l * dp[i + 2];
                }
                else if (s[i + 1] >= '0' && s[i + 1] <= '6')
                {
                    return dp[i + 2];
                }
            }
            return 0;
        };
        for (int i = n - 1; i >= 0; i--)
        {
            dp[i] = (case1(i) + case2(i)) % MOD;
        }
        return dp[0];
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
    EXPECT_EQ(solution.numDecodings("*"), 9);
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.numDecodings("1*"), 18);
}

TEST_F(LeetCodeTest, Example3)
{
    EXPECT_EQ(solution.numDecodings("2*"), 15);
}