#pragma once
#include "Common.h"

class NumMatrix
{
public:
    NumMatrix(vector<vector<int>> &matrix)
    {
    }

    int sumRegion(int row1, int col1, int row2, int col2)
    {
        return 0;
    }
};

class Solution
{
};

class LeetCodeTest : public testing::Test
{
public:
    static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<vector<int>> matrix = {
        {3, 0, 1, 4, 2},
        {5, 6, 3, 2, 1},
        {1, 2, 0, 1, 5},
        {4, 1, 0, 1, 7},
        {1, 0, 3, 0, 5}};
    unique_ptr<NumMatrix> obj(new NumMatrix(matrix));

    EXPECT_EQ(obj->sumRange(2, 1, 4, 3), 8);
    EXPECT_EQ(obj->sumRange(1, 1, 2, 2), 11);
    EXPECT_EQ(obj->sumRange(1, 2, 2, 4), 12);
}
