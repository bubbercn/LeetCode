#pragma once
#include "Common.h"

class Solution
{
public:
    bool isRationalEqual(string_view s, string_view t)
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
    EXPECT_EQ(solution.isRationalEqual("0.(52)", "0.5(25)"), true);
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.isRationalEqual("0.1666(6)", "0.166(66)"), true);
}

TEST_F(LeetCodeTest, Example3)
{
    EXPECT_EQ(solution.isRationalEqual("0.9(9)", "1."), true);
}
