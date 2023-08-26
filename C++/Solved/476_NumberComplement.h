#pragma once
#include "Common.h"

class Solution
{
public:
    int findComplement(int num)
    {
        bool found1 = false;
        for (int i = sizeof(num) * 8 - 1; i >= 0; i--)
        {
            if (((1 << i) & num) != 0)
            {
                found1 = true;
            }
            else if (!found1)
            {
                continue;
            }
            num ^= (1 << i);
        }
        return num;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    EXPECT_EQ(solution.findComplement(5), 2);
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.findComplement(1), 0);
}