#pragma once
#include "Common.h"

class Solution
{
public:
    int kthGrammar(int n, int k)
    {
        return 0;
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