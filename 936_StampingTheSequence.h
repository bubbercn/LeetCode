#pragma once
#include "Common.h"

class Solution
{
public:
    vector<int> movesToStamp(string_view stamp, string_view target)
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
    vector<int> output = {0, 2};
    EXPECT_EQ(solution.movesToStamp("abc", "ababc"), output);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> output = {3, 0, 1};
    EXPECT_EQ(solution.movesToStamp("abca", "aabcaca"), output);
}