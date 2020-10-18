#pragma once
#include "Common.h"

class Solution
{
public:
    int integerBreak(int n)
    {
        if (n <= 0)
            return 0;
        
        if (n == 1)
            return 0;
        
        if (n == 2)
            return 1;
        
        if (n == 3)
            return 2;
        
        int numberOf3 = n / 3;
        if (n % 3 == 0)
        {
            return static_cast<int>(pow(3, numberOf3));
        }
        else if (n % 3 == 1)
        {
            return 4 * static_cast<int>(pow(3, numberOf3 - 1));
        }
        else
        {
            return 2 * static_cast<int>(pow(3, numberOf3));
        }
    }
};

class LeetCodeTest : public testing::Test
{
public:
    static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    EXPECT_EQ(solution.integerBreak(2), 1);
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.integerBreak(10), 36);
}
