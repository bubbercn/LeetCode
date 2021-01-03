#pragma once
#include "Common.h"

class Solution
{
public:
    int findNthDigit(int n)
    {
        int begin = 1;
        int end = 10;
        long count = 9;
        long preCount = 0;
        int digitCount = 1;
        while (n > count)
        {
            digitCount++;
            begin = end;
            end *= 10;
            preCount = count;
            count += static_cast<long>(end - begin) * digitCount;
        }
        int num = (n - preCount - 1) / digitCount + begin;
        int digit = (n - preCount + digitCount - 1) % digitCount;
        return getDigit(num, digitCount - digit);
    }
private:
    int getDigit(int num, int digit)
    {
        while(digit-- > 1)
        {
            num /= 10;
        }
        return num % 10;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    EXPECT_EQ(solution.findNthDigit(3), 3);
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.findNthDigit(11), 0);
}

TEST_F(LeetCodeTest, Failure1)
{
    EXPECT_EQ(solution.findNthDigit(10), 1);
}

TEST_F(LeetCodeTest, Case_INT_MAX)
{
    EXPECT_EQ(solution.findNthDigit(INT_MAX), 1);
}
