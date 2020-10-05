#pragma once
#include "Common.h"

class Solution
{
public:
    vector<string> findItinerary(vector<vector<string>> &tickets)
    {
        return {};
    }
};

class LeetCodeTest : public testing::Test
{
public:
    static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<vector<string>> input = {{"MUC", "LHR"}, {"JFK", "MUC"}, {"SFO", "SJC"}, {"LHR", "SFO"}};
    vector<string> output = {"JFK", "MUC", "LHR", "SFO", "SJC"};
    EXPECT_EQ(solution.findItinerary(input), output);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<vector<string>> input = {{"JFK", "SFO"}, {"JFK", "ATL"}, {"SFO", "ATL"}, {"ATL", "JFK"}, {"ATL", "SFO"}};
    vector<string> output = {"JFK", "ATL", "JFK", "SFO", "ATL", "SFO"};
    EXPECT_EQ(solution.findItinerary(input), output);
}
