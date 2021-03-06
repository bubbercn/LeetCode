#pragma once
#include "Common.h"

class Solution
{
public:
    int strongPasswordChecker(string password)
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
    EXPECT_EQ(solution.strongPasswordChecker("a"), 5);
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.strongPasswordChecker("aA1"), 3);
}

TEST_F(LeetCodeTest, Example3)
{
    EXPECT_EQ(solution.strongPasswordChecker("1337C0d3"), 0);
}