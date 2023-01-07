#pragma once
#include "Common.h"

class Solution
{
public:
    double mincostToHireWorkers(vector<int> &quality, vector<int> &wage, int k)
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
    vector<int> quality = {10, 20, 5};
    vector<int> wage = {70, 50, 30};
    EXPECT_EQ(solution.mincostToHireWorkers(quality, wage, 2), 105);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> quality = {3, 1, 10, 10, 1};
    vector<int> wage = {4, 8, 2, 2, 7};
    EXPECT_EQ(solution.mincostToHireWorkers(quality, wage, 3), 30.66667);
}