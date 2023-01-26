#pragma once
#include "Common.h"

class Solution
{
public:
    int primePalindrome(int n)
    {
        int digitCount = getDigitCount(n);
        while (true)
        {
            int count = (digitCount + 1) / 2;
            int begin = pow(10, count - 1);
            int end = begin * 10;
            for (int i = begin; i < end; i++)
            {
                string s1 = to_string(i);
                string s2 = s1.substr(0, digitCount - count);
                reverse(s2.begin(), s2.end());
                s1 += s2;
                int v = stoi(s1);
                if (v < n)
                    continue;
                if (isPrime(v))
                    return v;
            }
            digitCount++;
        }
        return 0;
    }

private:
    int getDigitCount(int n)
    {
        int result = 0;
        while (n > 0)
        {
            n /= 10;
            result++;
        }
        return result;
    }

    bool isPrime(int n)
    {
        if (n <= 1)
            return false;

        if (n == 2 || n == 3)
            return true;

        for (int i = 2; i * i <= n; i++)
        {
            if (n % i == 0)
                return false;
        }
        return true;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    EXPECT_EQ(solution.primePalindrome(6), 7);
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.primePalindrome(8), 11);
}

TEST_F(LeetCodeTest, Example3)
{
    EXPECT_EQ(solution.primePalindrome(13), 101);
}

TEST_F(LeetCodeTest, Failure1)
{
    EXPECT_EQ(solution.primePalindrome(9989900), 100030001);
}