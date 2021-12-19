#pragma once
#include "Common.h"

class Solution
{
public:
    int countSubstrings(string_view s)
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
    EXPECT_EQ(solution.countSubstrings("abc"), 3);
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.countSubstrings("aaa"), 6);
}