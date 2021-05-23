#pragma once
#include "Common.h"

class Solution
{
public:
    int findSubstringInWraproundString(string p)
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
    EXPECT_EQ(solution.findSubstringInWraproundString("a"), 1);
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.findSubstringInWraproundString("cac"), 2);
}

TEST_F(LeetCodeTest, Example3)
{
    EXPECT_EQ(solution.findSubstringInWraproundString("zab"), 6);
}