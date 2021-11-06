#pragma once
#include "Common.h"

class Solution
{
public:
    bool checkInclusion(string_view s1, string_view s2)
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
    EXPECT_EQ(solution.checkInclusion("ab", "eidbaooo"), true);
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.checkInclusion("ab", "eidboaoo"), false);
}