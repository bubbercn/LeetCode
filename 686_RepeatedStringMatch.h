#pragma once
#include "Common.h"

class Solution
{
public:
    int repeatedStringMatch(string_view a, string_view b)
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
    EXPECT_EQ(solution.repeatedStringMatch("abcd", "cdabcdab"), 3);
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.repeatedStringMatch("a", "aa"), 2);
}