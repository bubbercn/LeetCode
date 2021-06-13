#pragma once
#include "Common.h"

class Solution
{
public:
    int findRadius(vector<int> &houses, vector<int> &heaters)
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
    vector<int> houses = {1, 2, 3};
    vector<int> heaters = {2};
    EXPECT_EQ(solution.findRadius(houses, heaters), 1);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> houses = {1, 2, 3, 4};
    vector<int> heaters = {1, 4};
    EXPECT_EQ(solution.findRadius(houses, heaters), 1);
}

TEST_F(LeetCodeTest, Example3)
{
    vector<int> houses = {1, 5};
    vector<int> heaters = {2};
    EXPECT_EQ(solution.findRadius(houses, heaters), 3);
}