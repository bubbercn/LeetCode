#pragma once
#include "Common.h"

class Solution
{
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart)
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
    vector<vector<int>> output = {
        {0, 0},
        {0, 1},
        {0, 2},
        {0, 3},
    };
    EXPECT_EQ(solution.spiralMatrixIII(1, 4, 0, 0), output);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<vector<int>> output = {
        {1, 4},
        {1, 5},
        {2, 5},
        {2, 4},
        {2, 3},
        {1, 3},
        {0, 3},
        {0, 4},
        {0, 5},
        {3, 5},
        {3, 4},
        {3, 3},
        {3, 2},
        {2, 2},
        {1, 2},
        {0, 2},
        {4, 5},
        {4, 4},
        {4, 3},
        {4, 2},
        {4, 1},
        {3, 1},
        {2, 1},
        {1, 1},
        {0, 1},
        {4, 0},
        {3, 0},
        {2, 0},
        {1, 0},
        {0, 0},
    };
    EXPECT_EQ(solution.spiralMatrixIII(5, 6, 1, 4), output);
}