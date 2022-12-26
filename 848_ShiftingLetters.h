#pragma once
#include "Common.h"

class Solution
{
public:
    string shiftingLetters(string_view s, vector<int> &shifts)
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
    vector<int> shifts = {3, 5, 9};
    EXPECT_EQ(solution.shiftingLetters("abc", shifts), "rpl");
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> shifts = {1, 2, 3};
    EXPECT_EQ(solution.shiftingLetters("aaa", shifts), "gfd");
}