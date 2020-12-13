#pragma once
#include "Common.h"

class Solution
{
public:
    int kthSmallest(vector<vector<int>> &matrix, int k)
    {
        if (matrix.empty())
            return 0;

        if (matrix.at(0).empty())
            return 0;

        int rowCount = matrix.size();
        int colCount = matrix.at(0).size();

        int left = matrix[0][0];
        int right = matrix[rowCount - 1][colCount - 1];

        while (left <= right)
        {
            int middle = left + (right - left) / 2;
            int temp = check(matrix, k, middle);
            if (temp == 0)
            {
                return middle;
            }
            else if (temp < 0)
            {
                right = middle - 1;
            }
            else
            {
                left = middle + 1;
            }
        }

        return left;
    }

private:
    int check(vector<vector<int>> &matrix, int k, int target)
    {
        int total = 0;
        int cur = matrix.at(0).size() - 1;
        int max = INT_MIN;
        for (int i = 0; i < matrix.size(); i++)
        {
            while (cur >= 0 && matrix[i][cur] > target)
            {
                cur--;
            }
            if (cur >= 0)
            {
                max = ::max(max, matrix[i][cur]);
            }
            total += (cur + 1);
        }

        if (total < k)
        {
            return 1;
        }
        else if (total == k && max == target)
        {
            return 0;
        }
        else
        {
            return -1;
        }
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
    inline static vector<vector<int>> matrix;
};

TEST_F(LeetCodeTest, Example1)
{
    matrix = {{1, 5, 9},
              {10, 11, 13},
              {12, 13, 15}};
    EXPECT_EQ(solution.kthSmallest(matrix, 8), 13);
}

TEST_F(LeetCodeTest, Case1)
{
    matrix = {{1, 5, 9},
              {10, 11, 13},
              {12, 13, 15}};
    EXPECT_EQ(solution.kthSmallest(matrix, 7), 13);
}

TEST_F(LeetCodeTest, Case2)
{
    matrix = {{1, 5, 9},
              {10, 11, 13},
              {12, 13, 15}};
    EXPECT_EQ(solution.kthSmallest(matrix, 6), 12);
}

TEST_F(LeetCodeTest, Failure1)
{
    matrix = {{1, 1, 3, 8, 13},
              {4, 4, 4, 8, 18},
              {9, 14, 18, 19, 20},
              {14, 19, 23, 25, 25},
              {18, 21, 26, 28, 29}};

    EXPECT_EQ(solution.kthSmallest(matrix, 13), 18);
}