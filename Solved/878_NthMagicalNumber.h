#pragma once
#include "Common.h"

class Solution
{
public:
    int nthMagicalNumber(int n, int a, int b)
    {
        int maxCommonFactor = commonFactor(a, b);
        int minCommonMultiple = a / maxCommonFactor * b;
        int inc = minCommonMultiple / a + minCommonMultiple / b - 1;
        int count = 0;
        long result = 0;

        int x = (n + inc - 1) / inc;
        count = x * inc;
        result = static_cast<long>(x) * minCommonMultiple;
        result %= MOD;

        if (a > b)
            swap(a, b);

        int resultA = result;
        int resultB = result;
        int tA = minCommonMultiple;
        int tB = minCommonMultiple;
        while (count > n)
        {
            if (tA - a > tB - b)
            {
                tA -= a;
                resultA -= a;
                result = resultA;
            }
            else
            {
                tB -= b;
                resultB -= b;
                result = resultB;
            }
            result %= MOD;
            if (result < 0)
                result += MOD;
            count--;
        }

        return result;
    }

private:
    int commonFactor(int m, int n)
    {
        int result = n;
        while (m % n != 0)
        {
            result = m % n;
            m = n;
            n = result;
        }
        return result;
    }

    static constexpr int MOD = 1000000000 + 7;
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    EXPECT_EQ(solution.nthMagicalNumber(1, 2, 3), 2);
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.nthMagicalNumber(4, 2, 3), 6);
}

TEST_F(LeetCodeTest, Failure1)
{
    EXPECT_EQ(solution.nthMagicalNumber(1000000000, 40000, 40000), 999720007);
}

TEST_F(LeetCodeTest, Failure2)
{
    EXPECT_EQ(solution.nthMagicalNumber(1000000000, 39999, 40000), 999860007);
}