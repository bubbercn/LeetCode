#pragma once
#include "Common.h"

class Solution
{
public:
    int shoppingOffers(vector<int> &price, vector<vector<int>> &special, vector<int> &needs)
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
    vector<int> price = {2, 5};
    vector<vector<int>> special = {
        {3, 0, 5},
        {1, 2, 10},
    };
    vector<int> needs = {3, 2};
    EXPECT_EQ(solution.shoppingOffers(price, special, needs), 14);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> price = {2, 3, 4};
    vector<vector<int>> special = {
        {1, 1, 0, 4},
        {2, 2, 1, 9},
    };
    vector<int> needs = {1, 2, 1};
    EXPECT_EQ(solution.shoppingOffers(price, special, needs), 11);
}