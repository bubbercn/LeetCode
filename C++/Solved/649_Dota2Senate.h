#pragma once
#include "Common.h"

class Solution
{
public:
    string predictPartyVictory(string_view senate)
    {
        queue<int> Rs;
        queue<int> Ds;
        int n = senate.length();
        for (int i = 0; i < n; i++)
        {
            if (senate[i] == 'R')
            {
                Rs.emplace(i);
            }
            else
            {
                Ds.emplace(i);
            }
        }
        queue<int> *winnerList;
        while (!Rs.empty() && !Ds.empty())
        {
            if (Rs.front() < Ds.front())
            {
                winnerList = &Rs;
            }
            else
            {
                winnerList = &Ds;
            }
            winnerList->emplace(n + winnerList->front());
            Rs.pop();
            Ds.pop();
        }
        return Rs.empty() ? "Dire" : "Radiant";
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

TEST_F(LeetCodeTest, Case1)
{
    EXPECT_EQ(solution.predictPartyVictory("RRDDD"), "Radiant");
}

TEST_F(LeetCodeTest, Case2)
{
    EXPECT_EQ(solution.predictPartyVictory("RRDDDD"), "Dire");
}

TEST_F(LeetCodeTest, Failure1)
{
    EXPECT_EQ(solution.predictPartyVictory("DRRDRDRDRDDRDRDR"), "Radiant");
}