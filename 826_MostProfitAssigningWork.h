#pragma once
#include "Common.h"

class Solution
{
public:
    int maxProfitAssignment(vector<int> &difficulty, vector<int> &profit, vector<int> &worker)
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
    vector<int> difficulty = {2, 4, 6, 8, 10};
    vector<int> profit = {10, 20, 30, 40, 50};
    vector<int> worker = {4, 5, 6, 7};
    EXPECT_EQ(solution.maxProfitAssignment(difficulty, profit, worker), 100);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> difficulty = {85, 47, 57};
    vector<int> profit = {24, 66, 99};
    vector<int> worker = {40, 25, 25};
    EXPECT_EQ(solution.maxProfitAssignment(difficulty, profit, worker), 0);
}
