#pragma once
#include "Common.h"

class Solution
{
public:
    bool canVisitAllRooms(vector<vector<int>> &rooms)
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
    vector<vector<int>> rooms = {
        {1},
        {2},
        {3},
        {},
    };
    EXPECT_EQ(solution.canVisitAllRooms(rooms), true);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<vector<int>> rooms = {
        {1, 3},
        {3, 0, 1},
        {2},
        {0},
    };
    EXPECT_EQ(solution.canVisitAllRooms(rooms), false);
}