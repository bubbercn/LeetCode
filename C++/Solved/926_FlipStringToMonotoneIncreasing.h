#pragma once
#include "Common.h"

class Solution
{
public:
    int minFlipsMonoIncr(string_view s)
    {
        int n = s.length();
        int dp0 = s[0] == '0' ? 0 : 1;
        int dp1 = s[0] == '1' ? 0 : 1;
        int result = 0;
        for (int i = 1; i < n; i++)
        {
            if (s[i] == '0')
            {
                dp1 = min(dp0 + 1, dp1 + 1);
            }
            else
            {
                dp1 = min(dp0, dp1);
                dp0++;
            }
            result = max(result, min(dp0, dp1));
        }
        return result;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    EXPECT_EQ(solution.minFlipsMonoIncr("00110"), 1);
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.minFlipsMonoIncr("010110"), 2);
}

TEST_F(LeetCodeTest, Example3)
{
    EXPECT_EQ(solution.minFlipsMonoIncr("00011000"), 2);
}