#pragma once
#include "Common.h"

class Solution
{
public:
    int containVirus(vector<vector<int>> &isInfected)
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
    vector<vector<int>> isInfected = {
        {0, 1, 0, 0, 0, 0, 0, 1},
        {0, 1, 0, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0, 0, 0, 0},
    };
    EXPECT_EQ(solution.containVirus(isInfected), 10);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<vector<int>> isInfected = {
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1},
    };
    EXPECT_EQ(solution.containVirus(isInfected), 4);
}

TEST_F(LeetCodeTest, Example3)
{
    vector<vector<int>> isInfected = {
        {1, 1, 1, 0, 0, 0, 0, 0, 0},
        {1, 0, 1, 0, 1, 1, 1, 1, 1},
        {1, 1, 1, 0, 0, 0, 0, 0, 0},
    };
    EXPECT_EQ(solution.containVirus(isInfected), 13);
}