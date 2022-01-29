#pragma once
#include "Common.h"

class Solution
{
public:
    int cutOffTree(vector<vector<int>> &forest)
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
    vector<vector<int>> forest = {
        {1, 2, 3},
        {0, 0, 4},
        {7, 6, 5},
    };
    EXPECT_EQ(solution.cutOffTree(forest), 6);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<vector<int>> forest = {
        {1, 2, 3},
        {0, 0, 0},
        {7, 6, 5},
    };
    EXPECT_EQ(solution.cutOffTree(forest), -1);
}

TEST_F(LeetCodeTest, Example3)
{
    vector<vector<int>> forest = {
        {2, 3, 4},
        {0, 0, 5},
        {8, 7, 6},
    };
    EXPECT_EQ(solution.cutOffTree(forest), 6);
}
