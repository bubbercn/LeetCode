#pragma once
#include "Common.h"

class Solution
{
public:
    string frequencySort(string s)
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
    EXPECT_EQ(solution.frequencySort("tree"), "eetr");
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.frequencySort("cccaaa"), "cccaaa");
}

TEST_F(LeetCodeTest, Example3)
{
    EXPECT_EQ(solution.frequencySort("Aabb"), "bbAa");
}