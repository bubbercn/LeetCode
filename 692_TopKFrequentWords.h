#pragma once
#include "Common.h"

class Solution
{
public:
    vector<string> topKFrequent(vector<string> &words, int k)
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
    vector<string> words = {"i", "love", "leetcode", "i", "love", "coding"};
    vector<string> output = {"i", "love"};
    EXPECT_EQ(solution.topKFrequent(words, 2), output);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<string> words = {"the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"};
    vector<string> output = {"the", "is", "sunny", "day"};
    EXPECT_EQ(solution.topKFrequent(words, 4), output);
}