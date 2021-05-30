#pragma once
#include "Common.h"

class Solution
{
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string> &words)
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
    vector<string> words = {"cat", "cats", "catsdogcats", "dog", "dogcatsdog", "hippopotamuses", "rat", "ratcatdogcat"};
    vector<string> output = {"catsdogcats", "dogcatsdog", "ratcatdogcat"};
    EXPECT_EQ(solution.findAllConcatenatedWordsInADict(words), output);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<string> words = {"cat", "dog", "catdog"};
    vector<string> output = {"catdog"};
    EXPECT_EQ(solution.findAllConcatenatedWordsInADict(words), output);
}