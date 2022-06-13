#pragma once
#include "Common.h"

class Solution
{
public:
    int countPrimeSetBits(int left, int right)
    {
        int result = 0;
        for (int i = left; i <= right; i++)
        {
            bitset<32> temp(i);
            if (isPrime(temp.count()))
                result++;
        }
        return result;
    }

private:
    bool isPrime(int value)
    {
        if (value <= 1)
            return false;

        if (value == 2 || value == 3)
            return true;

        for (int i = 2; i * i <= value; i++)
        {
            if (value % i == 0)
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
    EXPECT_EQ(solution.countPrimeSetBits(6, 10), 4);
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.countPrimeSetBits(10, 15), 5);
}