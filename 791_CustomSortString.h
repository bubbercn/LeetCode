#pragma once
#include "Common.h"

class Solution
{
public:
    string customSortString(string_view order, string_view s)
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
    EXPECT_EQ(solution.customSortString("cba", "abcd"), "cbad");
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.customSortString("cbafg", "abcd"), "cbad");
}