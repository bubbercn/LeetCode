#pragma once
#include "Common.h"

class Solution
{
public:
    bool escapeGhosts(vector<vector<int>> &ghosts, vector<int> &target)
    {
        int dis = abs(target[0]) + abs(target[1]);
        for (auto &ghost : ghosts)
        {
            int dis2 = abs(ghost[0] - target[0]) + abs(ghost[1] - target[1]);
            if (dis2 <= dis)
                return false;
        }
        return true;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<vector<int>> ghosts = {{1, 0}, {0, 3}};
    vector<int> target = {0, 1};
    EXPECT_EQ(solution.escapeGhosts(ghosts, target), true);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<vector<int>> ghosts = {{1, 0}};
    vector<int> target = {2, 0};
    EXPECT_EQ(solution.escapeGhosts(ghosts, target), false);
}

TEST_F(LeetCodeTest, Example3)
{
    vector<vector<int>> ghosts = {{2, 0}};
    vector<int> target = {1, 0};
    EXPECT_EQ(solution.escapeGhosts(ghosts, target), false);
}