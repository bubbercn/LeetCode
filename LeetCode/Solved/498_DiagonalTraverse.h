#pragma once
#include "Common.h"

class Solution
{
public:
    vector<int> findDiagonalOrder(vector<vector<int>> &mat)
    {
        m = mat.size();
        n = mat[0].size();
        int i = 0, j = 0;
        up = true;
        vector<int> result(m * n);
        int k = 0;
        do
        {
            result[k++] = mat[i][j];
        } while (next(i, j));
        return result;
    }

private:
    int m;
    int n;
    bool up;
    bool next(int &i, int &j)
    {
        if (i == m - 1 && j == n - 1)
            return false;

        if (up)
        {
            i--;
            j++;
        }
        else
        {
            i++;
            j--;
        }

        if (i == -1 || i == m || j == -1 || j == n)
            up = !up;

        if (i == -1)
        {
            if (j == n)
            {
                i = 1;
                j = n - 1;
            }
            else
            {
                i = 0;
            }
        }
        else if (j == -1)
        {
            if (i == m)
            {
                i = m - 1;
                j = 1;
            }
            else
            {
                j = 0;
            }
        }
        else if (i == m)
        {
            i = m - 1;
            j += 2;
        }
        else if (j == n)
        {
            j = n - 1;
            i += 2;
        }

        return true;
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

TEST_F(LeetCodeTest, Case1)
{
    vector<vector<int>> mat = {
        {1},
    };
    vector<int> output = {1};
    EXPECT_EQ(solution.findDiagonalOrder(mat), output);
}

TEST_F(LeetCodeTest, Case2)
{
    vector<vector<int>> mat = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16},
    };
    vector<int> output = {1, 2, 5, 9, 6, 3, 4, 7, 10, 13, 14, 11, 8, 12, 15, 16};
    EXPECT_EQ(solution.findDiagonalOrder(mat), output);
}