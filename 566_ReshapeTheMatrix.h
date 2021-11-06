#pragma once
#include "Common.h"

class Solution
{
public:
    vector<vector<int>> matrixReshape(vector<vector<int>> &mat, int r, int c)
    {
        int m = mat.size();
        int n = mat[0].size();
        if (m * n != r * c)
            return mat;

        vector<vector<int>> result(r, vector<int>(c, 0));
        int k = 0, l = 0;
        ;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                result[k][l++] = mat[i][j];
                if (l == c)
                {
                    k++;
                    l = 0;
                }
            }
        }

        return result;
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
        {1, 2},
        {3, 4},
    };
    vector<vector<int>> output = {
        {1, 2, 3, 4},
    };
    EXPECT_EQ(solution.matrixReshape(mat, 1, 4), output);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<vector<int>> mat = {
        {1, 2},
        {3, 4},
    };
    vector<vector<int>> output = {
        {1, 2},
        {3, 4},
    };
    EXPECT_EQ(solution.matrixReshape(mat, 2, 4), output);
}
