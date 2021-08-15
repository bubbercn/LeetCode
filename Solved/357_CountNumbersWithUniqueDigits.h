#pragma once
#include "Common.h"

class Solution
{
public:
    int countNumbersWithUniqueDigits(int n)
    {
        if (n == 0)
            return 1;
        
        int result = 9;
        int i = 9;
        int x = n;
        while (x-- > 1)
        {
            result *= i--;
        }        

        return result + countNumbersWithUniqueDigits(n - 1);
    }
};

class LeetCodeTest : public testing::Test
{
public:
    static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    EXPECT_EQ(solution.countNumbersWithUniqueDigits(2), 91);
}