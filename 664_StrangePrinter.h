#pragma once
#include "Common.h"

class Solution
{
public:
    int strangePrinter(string_view s)
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
    EXPECT_EQ(solution.strangePrinter("aaabbb"), 2);
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.strangePrinter("aba"), 2);
}