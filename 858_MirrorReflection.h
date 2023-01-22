#pragma once
#include "Common.h"

class Solution
{
public:
    int mirrorReflection(int p, int q)
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
    EXPECT_EQ(solution.mirrorReflection(2, 1), 2);
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.mirrorReflection(3, 1), 1);
}