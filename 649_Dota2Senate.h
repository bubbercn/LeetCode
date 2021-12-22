#pragma once
#include "Common.h"

class Solution
{
public:
    string predictPartyVictory(string_view senate)
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
    EXPECT_EQ(solution.predictPartyVictory("RD"), "Radiant");
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.predictPartyVictory("RDD"), "Dire");
}