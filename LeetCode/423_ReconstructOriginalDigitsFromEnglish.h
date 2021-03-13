#pragma once
#include "Common.h"

class Solution
{
public:
    string originalDigits(string s)
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
    EXPECT_EQ(solution.originalDigits("owoztneoer"), "012");
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.originalDigits("fviefuro"), "45");
}