#pragma once
#include "Common.h"

class Solution
{
public:
    int profitableSchemes(int n, int minProfit, vector<int> &group, vector<int> &profit)
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
    vector<int> group = {2, 2};
    vector<int> profit = {2, 3};
    EXPECT_EQ(solution.profitableSchemes(5, 3, group, profit), 2);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> group = {2, 3, 5};
    vector<int> profit = {6, 7, 8};
    EXPECT_EQ(solution.profitableSchemes(10, 5, group, profit), 7);
}