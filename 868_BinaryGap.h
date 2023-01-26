#pragma once
#include "Common.h"

class Solution
{
public:
    int binaryGap(int n)
    {
        bitset<32> bits(n);
        int begin = -1;
        int result = 0;
        for (int i = 0; i < 32; i++)
        {
            if (bits.test(i))
            {
                if (begin != -1)
                {
                    result = max(result, i - begin);
                }
                begin = i;
            }
        }
        return result;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    EXPECT_EQ(solution.binaryGap(22), 2);
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.binaryGap(8), 0);
}

TEST_F(LeetCodeTest, Example3)
{
    EXPECT_EQ(solution.binaryGap(5), 2);
}

TEST_F(LeetCodeTest, Failure1)
{
    EXPECT_EQ(solution.binaryGap(2097160), 18);
}