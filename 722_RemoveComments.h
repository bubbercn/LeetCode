#pragma once
#include "Common.h"

class Solution
{
public:
    vector<string> removeComments(vector<string> &source)
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
    vector<string> source = {"/*Test program */", "int main()", "{ ", "  // variable declaration ", "int a, b, c;", "/* This is a test", "   multiline  ", "   comment for ", "   testing */", "a = b + c;", "}"};
    vector<string> output = {"int main()", "{ ", "  ", "int a, b, c;", "a = b + c;", "}"};
    EXPECT_EQ(solution.removeComments(source), output);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<string> source = {"a/*comment", "line", "more_comment*/b"};
    vector<string> output = {"ab"};
    EXPECT_EQ(solution.removeComments(source), output);
}