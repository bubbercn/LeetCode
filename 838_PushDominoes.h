#pragma once
#include "Common.h"

class Solution
{
public:
    string pushDominoes(string_view dominoes)
    {
        return {};
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    EXPECT_EQ(solution.pushDominoes("RR.L"), "RR.L");
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.pushDominoes(".L.R...LR..L.."), "LL.RR.LLRRLL..");
}
