#pragma once
#include "Common.h"

class Solution
{
public:
    int largestPalindrome(int n)
    {
        if (n == 1)
            return 9;
        int upper = pow(10, n) - 1;
        int lower = pow(10, n - 1);
        for (int i = upper; i >= lower; i--)
        {
            string s = to_string(i);
            string rs = s;
            reverse(rs.begin(), rs.end());
            string palindrome = s + rs;
            long palindromeNum = stol(palindrome);
            long temp = ceill(sqrt(palindromeNum));
            for (long j = upper; j * j >= palindromeNum; j--)
            {
                if (palindromeNum % j == 0)
                    return palindromeNum % 1337;
            }
        }
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
    EXPECT_EQ(solution.largestPalindrome(2), 987);
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.largestPalindrome(1), 9);
}