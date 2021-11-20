#pragma once
#include "Common.h"

class Solution
{
public:
    int maxCount(int m, int n, vector<vector<int>> &ops)
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
    vector<vector<int>> ops = {
        {2, 2},
        {3, 3},
    };
    EXPECT_EQ(solution.maxCount(3, 3, ops), 4);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<vector<int>> ops = {
        {2, 2},
        {3, 3},
        {3, 3},
        {3, 3},
        {2, 2},
        {3, 3},
        {3, 3},
        {3, 3},
        {2, 2},
        {3, 3},
        {3, 3},
        {3, 3},
    };
    EXPECT_EQ(solution.maxCount(3, 3, ops), 4);
}

TEST_F(LeetCodeTest, Example3)
{
    vector<vector<int>> ops = {};
    EXPECT_EQ(solution.maxCount(3, 3, ops), 9);
}