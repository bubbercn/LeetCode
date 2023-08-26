#pragma once
#include "Common.h"

class NumMatrix
{
public:
    NumMatrix(vector<vector<int>> &matrix)
    {
        if (matrix.empty())
            return;
        
        lookup = vector<vector<int>>(matrix.size(), vector<int>(matrix[0].size()));
        for (size_t i = 0; i < matrix.size(); i++)
        {
            int sum = 0;
            for (size_t j = 0; j < matrix[0].size(); j++)
            {
                sum += matrix[i][j];
                lookup[i][j] = sum;
            }
        }

        for (size_t j = 0; j < lookup[0].size(); j++)
        {
            int sum = 0;
            for (size_t i = 0; i < lookup.size(); i++)
            {
                sum += lookup[i][j];
                lookup[i][j] = sum;
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2)
    {
        return lookup[row2][col2] - (row1 == 0 ? 0 : lookup[row1 - 1][col2]) - (col1 == 0 ? 0 : lookup[row2][col1 - 1]) + (row1 == 0 || col1 == 0 ? 0 : lookup[row1 - 1][col1 - 1]);
    }

private:
    vector<vector<int>> lookup;
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

    EXPECT_EQ(obj->sumRegion(2, 1, 4, 3), 8);
    EXPECT_EQ(obj->sumRegion(1, 1, 2, 2), 11);
    EXPECT_EQ(obj->sumRegion(1, 2, 2, 4), 12);
    EXPECT_EQ(obj->sumRegion(0, 0, 0, 0), 3);
    EXPECT_EQ(obj->sumRegion(0, 0, 1, 1), 14);
    EXPECT_EQ(obj->sumRegion(0, 0, 1, 0), 8);
    EXPECT_EQ(obj->sumRegion(0, 0, 0, 1), 3);
}
