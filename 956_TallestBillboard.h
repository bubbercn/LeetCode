#pragma once
#include "Common.h"

class Solution
{
public:
    int tallestBillboard(vector<int> &rods)
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
    vector<int> rods = {1, 2, 3, 6};
    EXPECT_EQ(solution.tallestBillboard(rods), 6);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> rods = {1, 2, 3, 4, 5, 6};
    EXPECT_EQ(solution.tallestBillboard(rods), 10);
}

TEST_F(LeetCodeTest, Example3)
{
    vector<int> rods = {1, 2};
    EXPECT_EQ(solution.tallestBillboard(rods), 0);
}