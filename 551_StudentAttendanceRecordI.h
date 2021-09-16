#pragma once
#include "Common.h"

class Solution
{
public:
    bool checkRecord(string s)
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
    EXPECT_EQ(solution.checkRecord("PPALLP"), true);
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.checkRecord("PPALLL"), false);
}