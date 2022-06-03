#pragma once
#include "Common.h"

class Solution
{
public:
    bool pyramidTransition(string_view bottom, vector<string> &allowed)
    {
        int n = bottom.size();
        pyramid.assign(n, {});
        pyramid[n - 1] = bottom;
        for (int i = 0; i < n - 1; i++)
        {
            pyramid[i].assign(i + 1, '0');
        }
        lookup.clear();
        for (auto &rule : allowed)
        {
            lookup.emplace(rule.substr(0, 2), rule[2]);
        }
        return dfs(n - 1, 0);
    }

private:
    vector<string> pyramid;
    unordered_map<string, char> lookup;
    bool dfs(int floor, int start)
    {
        
        return false;
    }
    bool help
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