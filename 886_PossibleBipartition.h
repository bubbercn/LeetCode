#pragma once
#include "Common.h"

class Solution
{
public:
    bool possibleBipartition(int n, vector<vector<int>> &dislikes)
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