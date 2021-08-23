#pragma once
#include "Common.h"

class Solution
{
public:
    int findMinMoves(vector<int> &machines)
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
    vector<int> machines = {1, 0, 5};
    EXPECT_EQ(solution.findMinMoves(machines), 3);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> machines = {0, 3, 0};
    EXPECT_EQ(solution.findMinMoves(machines), 2);
}

TEST_F(LeetCodeTest, Example3)
{
    vector<int> machines = {0, 2, 0};
    EXPECT_EQ(solution.findMinMoves(machines), -1);
}
