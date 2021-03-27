#pragma once
#include "Common.h"

class Solution
{
public:
    int minMutation(string start, string end, vector<string> &bank)
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
    vector<string> bank = {"AACCGGTA"};
    EXPECT_EQ(solution.minMutation("AACCGGTT", "AACCGGTA", bank), 1);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<string> bank = {"AACCGGTA", "AACCGCTA", "AAACGGTA"};
    EXPECT_EQ(solution.minMutation("AACCGGTT", "AAACGGTA", bank), 2);
}

TEST_F(LeetCodeTest, Example3)
{
    vector<string> bank = {"AAAACCCC", "AAACCCCC", "AACCCCCC"};
    EXPECT_EQ(solution.minMutation("AAAAACCC", "AACCCCCC", bank), 3);
}