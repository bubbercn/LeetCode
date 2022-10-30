#pragma once
#include "Common.h"

class Solution
{
public:
    string findReplaceString(string_view s, vector<int> &indices, vector<string> &sources, vector<string> &targets)
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
    vector<int> indices = {0, 2};
    vector<string> sources = {"a", "cd"};
    vector<string> targets = {"eee", "ffff"};
    EXPECT_EQ(solution.findReplaceString("abcd", indices, sources, targets), "eeebffff");
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> indices = {0, 2};
    vector<string> sources = {"ab", "ec"};
    vector<string> targets = {"eee", "ffff"};
    EXPECT_EQ(solution.findReplaceString("abcd", indices, sources, targets), "eeecd");
}