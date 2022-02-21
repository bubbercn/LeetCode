#pragma once
#include "Common.h"

class Solution
{
public:
    bool hasAlternatingBits(int n)
    {
        int r = n & 1;
        n >>= 1;
        while (n > 0)
        {
            int temp = n & 1;
            if (!(temp ^ r))
                return false;
            r = temp;
            n >>= 1;
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
    EXPECT_EQ(solution.hasAlternatingBits(5), true);
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.hasAlternatingBits(7), false);
}

TEST_F(LeetCodeTest, Example3)
{
    EXPECT_EQ(solution.hasAlternatingBits(11), false);
}
