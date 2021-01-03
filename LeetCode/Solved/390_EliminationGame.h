#pragma once
#include "Common.h"

class Solution
{
public:
    int lastRemaining(int n)
    {
        if (n == 1)
            return 1;

        if (n & 1)
            return lastRemaining(n - 1);
        
        return 2 * (1 + n / 2 - lastRemaining(n / 2));
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    EXPECT_EQ(solution.lastRemaining(9), 6);
}
