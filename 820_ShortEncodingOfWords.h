#pragma once
#include "Common.h"

class Solution
{
public:
    int minimumLengthEncoding(vector<string> &words)
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
    vector<string> words = {"time", "me", "bell"};
    EXPECT_EQ(solution.minimumLengthEncoding(words), 10);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<string> words = {"t"};
    EXPECT_EQ(solution.minimumLengthEncoding(words), 2);
}