#pragma once
#include "Common.h"

class Solution
{
public:
    bool canTransform(string_view start, string_view end)
    {
        return false;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    EXPECT_EQ(solution.canTransform("RXXLRXRXL", "XRLXXRRLX"), true);
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.canTransform("X", "L"), false);
}