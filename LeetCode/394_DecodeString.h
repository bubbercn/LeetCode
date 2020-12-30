#pragma once
#include "Common.h"

class Solution
{
public:
    string decodeString(string s)
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
    EXPECT_EQ(solution.decodeString("3[a]2[bc]"), "aaabcbc");
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.decodeString("3[a2[c]]"), "accaccacc");
}

TEST_F(LeetCodeTest, Example3)
{
    EXPECT_EQ(solution.decodeString("2[abc]3[cd]ef"), "abcabccdcdcdef");
}

TEST_F(LeetCodeTest, Example4)
{
    EXPECT_EQ(solution.decodeString("abc3[cd]xyz"), "abccdcdcdxyz");
}