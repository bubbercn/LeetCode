#pragma once
#include "Common.h"

class Solution
{
public:
    vector<string> removeInvalidParentheses(string s)
    {
        for (int i = 0; i < s.length(); i++)
        {
        }
        return {};
    }
};

class LeetCodeTest : public testing::Test
{
public:
    static Solution solution;
};

TEST_F(LeetCodeTest, Case1)
{
    string input = "()())()";
    vector<string> output = {"()()()", "(())()"};
    EXPECT_EQ(solution.removeInvalidParentheses(input), output);
}