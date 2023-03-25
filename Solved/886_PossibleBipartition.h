#pragma once
#include "Common.h"

class Solution
{
public:
    bool possibleBipartition(int n, vector<vector<int>> &dislikes)
    {
        adj.assign(n + 1, unordered_set<int>());
        for (auto &dislike : dislikes)
        {
            adj[dislike[0]].emplace(dislike[1]);
            adj[dislike[1]].emplace(dislike[0]);
        }
        color.assign(n + 1, -1);
        for (int i = 1; i <= n; i++)
        {
            if (!dfs(i, -1))
                return false;
        }
        return true;
    }

private:
    bool dfs(int from, int expectedColor)
    {
        if (expectedColor == -1)
        {
            if (color[from] == -1)
            {
                color[from] = 0;
            }
            else
            {
                return true;
            }
        }
        else
        {
            if (color[from] == -1)
            {
                color[from] = expectedColor;
            }
            else if (color[from] != expectedColor)
            {
                return false;
            }
            else
            {
                return true;
            }
        }

        int nextColor = color[from] == 0 ? 1 : 0;
        for (auto to : adj[from])
        {
            if (!dfs(to, nextColor))
                return false;
        }

        return true;
    }
    vector<unordered_set<int>> adj;
    vector<int> color;
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<vector<int>> dislikes = {
        {1, 2},
        {1, 3},
        {2, 4},
    };
    EXPECT_EQ(solution.possibleBipartition(4, dislikes), true);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<vector<int>> dislikes = {
        {1, 2},
        {1, 3},
        {2, 3},
    };
    EXPECT_EQ(solution.possibleBipartition(3, dislikes), false);
}