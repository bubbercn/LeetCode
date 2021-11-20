#pragma once
#include "Common.h"

class Solution
{
public:
    string fractionAddition(string_view expression)
    {
        int cNumerator = 0;
        int cDenominator = 1;
        int nNumerator = 0;
        int nDenominator = 1;
        bool plus = true;
        bool isProcessingNumerator = true;
        auto calc = [&]()
        {
            if (cDenominator % nDenominator == 0)
            {
                nNumerator = nNumerator * cDenominator / nDenominator;
            }
            else
            {
                int temp = cDenominator;
                cNumerator *= nDenominator;
                cDenominator *= nDenominator;
                nNumerator *= temp;
            }
            if (plus)
            {
                cNumerator += nNumerator;
            }
            else
            {
                cNumerator -= nNumerator;
            }
        };
        for (int i = 0; i < expression.length(); i++)
        {
            if (expression[i] >= '0' && expression[i] <= '9')
            {
                if (isProcessingNumerator)
                {
                    nNumerator = nNumerator * 10 + expression[i] - '0';
                }
                else
                {
                    nDenominator = nDenominator * 10 + expression[i] - '0';
                }
            }
            else if (expression[i] == '+' || expression[i] == '-')
            {
                calc();
                plus = expression[i] == '+';
                isProcessingNumerator = true;
                nNumerator = 0;
            }
            else
            {
                isProcessingNumerator = false;
                nDenominator = 0;
            }
        }
        calc();
        [&]()
        {
            if (cNumerator == 0)
            {
                cDenominator = 1;
                return;
            }
            int a = abs(cNumerator);
            int b = cDenominator;
            while (a % b != 0)
            {
                int c = a % b;
                a = b;
                b = c;
            }
            cNumerator /= b;
            cDenominator /= b;
        }();
        return to_string(cNumerator) + "/" + to_string(cDenominator);
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    EXPECT_EQ(solution.fractionAddition("-1/2+1/2"), "0/1");
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.fractionAddition("-1/2+1/2+1/3"), "1/3");
}

TEST_F(LeetCodeTest, Example3)
{
    EXPECT_EQ(solution.fractionAddition("1/3-1/2"), "-1/6");
}

TEST_F(LeetCodeTest, Example4)
{
    EXPECT_EQ(solution.fractionAddition("5/3+1/3"), "2/1");
}