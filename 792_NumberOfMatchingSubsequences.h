#pragma once
#include "Common.h"

class Solution
{
public:
    int numMatchingSubseq(string_view s, vector<string> &words)
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
    vector<string> words = {"a", "bb", "acd", "ace"};
    EXPECT_EQ(solution.numMatchingSubseq("abcde", words), 3);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<string> words = {"ahjpjau", "ja", "ahbwzgqnuk", "tnmlanowax"};
    EXPECT_EQ(solution.numMatchingSubseq("dsahjpjauf", words), 2);
}