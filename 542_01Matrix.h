#pragma once
#include "Common.h"

class Solution
{
public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
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
        {0, 0, 0},
        {0, 1, 0},
        {0, 0, 0},
    };
    vector<vector<int>> output = {
        {0, 0, 0},
        {0, 1, 0},
        {0, 0, 0},
    };
    EXPECT_EQ(solution.updateMatrix(mat), output);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<vector<int>> mat = {
        {0, 0, 0},
        {0, 1, 0},
        {1, 1, 1},
    };
    vector<vector<int>> output = {
        {0, 0, 0},
        {0, 1, 0},
        {1, 2, 1},
    };
    EXPECT_EQ(solution.updateMatrix(mat), output);
}