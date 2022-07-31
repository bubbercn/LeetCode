#pragma once
#include "Common.h"

class Solution
{
public:
    bool rotateString(string s, const string& goal)
    {
        if (goal.length() != s.length())
            return false;
        s += s;
        return s.find(goal) != string::npos;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    EXPECT_EQ(solution.rotateString("abcde", "cdeab"), true);
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.rotateString("abcde", "abced"), false);
}

