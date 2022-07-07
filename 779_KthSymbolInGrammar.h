#pragma once
#include "Common.h"

class Solution
{
public:
    int kthGrammar(int n, int k)
    {
        if (n == 1)
            return 0;
        int temp = kthGrammar(n - 1, (k + 1) / 2);
        return !(temp ^ (k % 2));
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    EXPECT_EQ(solution.kthGrammar(1, 1), 0);
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.kthGrammar(2, 1), 0);
}

TEST_F(LeetCodeTest, Example3)
{
    EXPECT_EQ(solution.kthGrammar(2, 2), 1);
}

TEST_F(LeetCodeTest, Failure1)
{
    EXPECT_EQ(solution.kthGrammar(3, 2), 1);
}