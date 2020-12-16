#pragma once
#include "Common.h"

inline static int pick = 0;

int guess(int num)
{
    if (pick < num)
    {
        return -1;
    }
    else if (pick > num)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

class Solution
{
public:
    int guessNumber(int n)
    {
        long begin = 1;
        long end = n;
        while (begin <= end)
        {
            long middle = (begin + end) / 2;
            if (int guess = ::guess(middle); guess == 0)
            {
                return middle;
            }
            else if (guess == 1)
            {
                begin = middle + 1;
            }
            else
            {
                end = middle - 1;
            }
        }
        return 0;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    pick = 6;
    EXPECT_EQ(solution.guessNumber(10), 6);
}

TEST_F(LeetCodeTest, Example2)
{
    pick = 1;
    EXPECT_EQ(solution.guessNumber(1), 1);
}

TEST_F(LeetCodeTest, Example3)
{
    pick = 1;
    EXPECT_EQ(solution.guessNumber(2), 1);
}

TEST_F(LeetCodeTest, Example4)
{
    pick = 2;
    EXPECT_EQ(solution.guessNumber(2), 2);
}