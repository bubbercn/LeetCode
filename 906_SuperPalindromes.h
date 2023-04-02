#pragma once
#include "Common.h"

class Solution
{
public:
    int superpalindromesInRange(string_view left, string_view right)
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
    EXPECT_EQ(solution.superpalindromesInRange("4", "1000"), 4);
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.superpalindromesInRange("1", "2"), 1);
}