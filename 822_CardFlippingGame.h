#pragma once
#include "Common.h"

class Solution
{
public:
    int flipgame(vector<int> &fronts, vector<int> &backs)
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
    vector<int> fronts = {1, 2, 4, 4, 7};
    vector<int> backs = {1, 3, 4, 1, 3};
    EXPECT_EQ(solution.flipgame(fronts, backs), 2);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> fronts = {1};
    vector<int> backs = {1};
    EXPECT_EQ(solution.flipgame(fronts, backs), 0);
}