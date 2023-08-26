#pragma once
#include "Common.h"

class Solution
{
public:
    int maximumSwap(int num)
    {
        string digits = to_string(num);
        for (int i = 0; i < digits.size() - 1; i++)
        {
            int maxValue = 0;
            int maxIndex = 0;
            for (int j = digits.size() - 1; j > i ; j--)
            {
                if (digits[j] > digits[i] && (maxIndex == 0 || digits[j] > maxValue))
                {
                    maxIndex = j;
                    maxValue = digits[j];
                }
            }
            if (maxIndex != 0)
            {
                swap(digits[i], digits[maxIndex]);
                break;
            }
        }
        return stoi(digits);
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    EXPECT_EQ(solution.maximumSwap(2736), 7236);
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.maximumSwap(9973), 9973);
}

TEST_F(LeetCodeTest, Failure1)
{
    EXPECT_EQ(solution.maximumSwap(1993), 9913);
}