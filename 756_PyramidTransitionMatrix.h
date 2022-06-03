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
            lookup[rule.substr(0, 2)].emplace_back(rule[2]);
        }
        return dfs(n - 1);
    }

private:
    vector<string> pyramid;
    unordered_map<string, vector<char>> lookup;
    bool dfs(int floor)
    {
        if (floor == 0)
            return true;

        vector<vector<char>> limit;
        vector<int> state(floor, 0);
        for (int i = 0; i < floor; i++)
        {
            if (auto it = lookup.find(pyramid[floor].substr(i, 2)); it == lookup.end())
            {
                return false;
            }
            else
            {
                limit.emplace_back(it->second);
            }
        }

        do
        {
            for (int i = 0; i < floor; i++)
            {
                pyramid[floor - 1][i] = limit[i][state[i]];
            }
            if (dfs(floor - 1))
                return true;
        } while (next(limit, state));

        return false;
    }

private:
    bool next(const vector<vector<char>> &limit, vector<int>& state)
    {
        for (int i = 0; i < limit.size(); i++)
        {
            state[i]++;
            if (state[i] == limit[i].size())
            {
                state[i] = 0;
            }
            else
            {
                return true;
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