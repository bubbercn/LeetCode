#pragma once
#include "Common.h"

class Solution
{
public:
    int uniqueLetterString(string_view s)
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
    EXPECT_EQ(solution.uniqueLetterString("ABC"), 10);
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.uniqueLetterString("ABA"), 8);
}

TEST_F(LeetCodeTest, Example3)
{
    EXPECT_EQ(solution.uniqueLetterString("LEETCODE"), 92);
}