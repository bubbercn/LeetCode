#pragma once
#include "Common.h"

class Solution
{
public:
    string removeDuplicateLetters(string s)
    {
        return {};
    }
};

class LeetCodeTest : public testing::Test
{
public:
    static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    EXPECT_EQ(solution.removeDuplicateLetters("bcabc"), "abc");
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.removeDuplicateLetters("cbacdcbc"), "acdb");
}
