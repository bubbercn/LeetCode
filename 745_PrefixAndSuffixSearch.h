#pragma once
#include "Common.h"

class WordFilter
{
public:
    WordFilter(vector<string> &words)
    {
    }

    int f(string prefix, string suffix)
    {
        return 0;
    }
};

class Solution
{
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<string> words = {"apple"};
    WordFilter wordFilter(words);
    EXPECT_EQ(wordFilter.f("a", "e"), 0);
}