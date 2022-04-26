#pragma once
#include "Common.h"

class Solution
{
public:
    int monotoneIncreasingDigits(int n)
    {
        vector<int> digits;
        if (n == 0)
            digits.emplace_back(0);
        while (n > 0)
        {
            digits.emplace_back(n % 10);
            n /= 10;
        }
        int limit = digits.size() - 1;
        for (int i = 0; i < limit; i++)
        {
            if (digits[i] < digits[i + 1])
            {
                for (int j = 0; j <= i; j++)
                {
                    digits[j] = 9;
                }
                digits[i + 1]--;
            }
        }
        int result = 0;
        for (int i = digits.size() - 1; i >= 0; i--)
        {
            result *= 10;
            result += digits[i];
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
    EXPECT_EQ(solution.monotoneIncreasingDigits(10), 9);
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.monotoneIncreasingDigits(1234), 1234);
}

TEST_F(LeetCodeTest, Example3)
{
    EXPECT_EQ(solution.monotoneIncreasingDigits(332), 299);
}

TEST_F(LeetCodeTest, Failure1)
{
    EXPECT_EQ(solution.monotoneIncreasingDigits(100), 99);
}