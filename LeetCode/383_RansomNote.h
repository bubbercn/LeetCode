#pragma once
#include "Common.h"

class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
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
    EXPECT_EQ(solution.canConstruct("a", "b"), false);
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.canConstruct("aa", "ab"), false);
}

TEST_F(LeetCodeTest, Example3)
{
    EXPECT_EQ(solution.canConstruct("aa", "aab"), true);
}