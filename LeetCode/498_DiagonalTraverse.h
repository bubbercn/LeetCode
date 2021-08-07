#pragma once
#include "Common.h"

class Solution
{
public:
    vector<int> findDiagonalOrder(vector<vector<int>> &mat)
    {
        return {};
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<vector<int>> mat = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
    };
    vector<int> output = {1, 2, 4, 7, 5, 3, 6, 8, 9};
    EXPECT_EQ(solution.findDiagonalOrder(mat), output);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<vector<int>> mat = {
        {1, 2},
        {3, 4},
    };
    vector<int> output = {1, 2, 3, 4};
    EXPECT_EQ(solution.findDiagonalOrder(mat), output);
}