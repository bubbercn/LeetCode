#pragma once
#include "Common.h"

class Solution
{
public:
    bool pyramidTransition(string_view bottom, vector<string> &allowed)
    {
        int n = bottom.size();
        lookup.clear();
        for (auto &rule : allowed)
        {
            string_view view(rule);
            lookup[view.substr(0, 2)].emplace_back(rule[2]);
        }
        string temp;
        return dfs(bottom, temp);
    }

private:
    unordered_map<string_view, vector<char>> lookup;
    bool dfs(string_view bottom, string &upper)
    {
        int n = bottom.length();
        if (n == 1)
            return true;

        int start = upper.length();
        if (start == n - 1)
        {
            string temp;
            return dfs(upper, temp);
        }

        if (auto it = lookup.find(bottom.substr(start, 2)); it != lookup.end())
        {
            for (auto c : it->second)
            {
                upper.push_back(c);
                if (dfs(bottom, upper))
                    return true;
                upper.pop_back();
            }
        }
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