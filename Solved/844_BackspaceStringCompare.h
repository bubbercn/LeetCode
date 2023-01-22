#pragma once
#include "Common.h"

class Solution
{
public:
    bool backspaceCompare(string_view s, string_view t)
    {
        return getPattern(s) == getPattern(t);
    }

private:
    string getPattern(string_view s)
    {
        list<char> pattern;
        for (auto c : s)
        {
            if (c == '#')
            {
                if (!pattern.empty())
                    pattern.pop_back();
            }
            else
                pattern.emplace_back(c);
        }
        return {pattern.begin(), pattern.end()};
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    EXPECT_EQ(solution.backspaceCompare("ab#c", "ad#c"), true);
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.backspaceCompare("ab##", "c#d#"), true);
}

TEST_F(LeetCodeTest, Example3)
{
    EXPECT_EQ(solution.backspaceCompare("a#c", "b"), false);
}

TEST_F(LeetCodeTest, Failure1)
{
    EXPECT_EQ(solution.backspaceCompare("a##c", "#a#c"), true);
}