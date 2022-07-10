#pragma once
#include "Common.h"

class Solution
{
public:
    vector<string> letterCasePermutation(string_view s)
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
    vector<string> output = {"a1b2", "a1B2", "A1b2", "A1B2"};
    EXPECT_EQ(solution.letterCasePermutation("a1b2"), output);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<string> output = {"3z4", "3Z4"};
    EXPECT_EQ(solution.letterCasePermutation("3z4"), output);
}
