#pragma once
#include "Common.h"

class Solution
{
public:
    int countBinarySubstrings(string_view s)
    {
        int n = s.length();
        int result = 0;
        for (int i = 0; i < n - 1; i++)
        {
            if (s[i] != s[i + 1])
            {
                result++;
                for (int left = i - 1, right = i + 2; left >= 0 && s[left] == s[left + 1] && right < n && s[right] == s[right - 1]; left--, right++)
                {
                    result++;
                }
            }
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
    EXPECT_EQ(solution.countBinarySubstrings("00110011"), 6);
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.countBinarySubstrings("10101"), 4);
}