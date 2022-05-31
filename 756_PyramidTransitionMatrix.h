#pragma once
#include "Common.h"

class Solution
{
public:
    bool pyramidTransition(string bottom, vector<string> &allowed)
    {
        return false;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<string> allowed = {"BCC", "CDE", "CEA", "FFF"};
    EXPECT_EQ(solution.pyramidTransition("BCD", allowed), true);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<string> allowed = {"AAB", "AAC", "BCD", "BBE", "DEF"};
    EXPECT_EQ(solution.pyramidTransition("AAAA", allowed), false);
}