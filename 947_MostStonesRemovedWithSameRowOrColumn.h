#pragma once
#include "Common.h"

class Solution
{
public:
    int removeStones(vector<vector<int>> &stones)
    {
        return 0;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<vector<int>> stones = {
        {0, 0},
        {0, 1},
        {1, 0},
        {1, 2},
        {2, 1},
        {2, 2},
    };
    EXPECT_EQ(solution.removeStones(stones), 5);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<vector<int>> stones = {
        {0, 0},
        {0, 2},
        {1, 1},
        {2, 0},
        {2, 2},
    };
    EXPECT_EQ(solution.removeStones(stones), 3);
}

TEST_F(LeetCodeTest, Example3)
{
    vector<vector<int>> stones = {
        {0, 0},
    };
    EXPECT_EQ(solution.removeStones(stones), 0);
}