#pragma once
#include "Common.h"

class Solution
{
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>> &matrix)
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
    vector<vector<int>> matrix = {
        {1, 2, 2, 3, 5},
        {3, 2, 3, 4, 4},
        {2, 4, 5, 3, 1},
        {6, 7, 1, 4, 5},
        {5, 1, 1, 2, 4},
    };
    vector<vector<int>> output = {
        {0, 4},
        {1, 3},
        {1, 4},
        {2, 2},
        {3, 0},
        {3, 1},
        {4, 0},
    };
    EXPECT_EQ(solution.pacificAtlantic(matrix), output);
}