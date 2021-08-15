#pragma once
#include "Common.h"

class Solution
{
public:
    int maxSumSubmatrix(vector<vector<int>> &matrix, int k)
    {
        int max = INT_MIN;
        for (int i = 0; i < matrix[0].size(); i++)
        {
            vector<int> rowSum(matrix.size(), 0);
            for (int col = i; col < matrix[0].size(); col++)
            {
                for (int row = 0; row < matrix.size(); row++)
                {
                    rowSum[row] += matrix[row][col];
                }
                max = ::max(max, maxSubArray(rowSum, k));
            }
        }
        return max;
    }

private:
    int maxSubArray(const vector<int> &nums, int k)
    {
        int result = INT_MIN;
        int sum = 0;
        set<int> sumSet;
        sumSet.emplace(0);
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            auto it = sumSet.lower_bound(sum - k);
            if (it != sumSet.end())
            {
                if (*it == sum - k)
                {
                    return k;
                }
                result = max(result, sum - *it);
            }
            sumSet.emplace(sum);
        }
        return result;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
   vector<vector<int>> matrix = {{1, 0, 1}, {0, -2, 3}};
   EXPECT_EQ(solution.maxSumSubmatrix(matrix, 2), 2);
}

TEST_F(LeetCodeTest, Failure1)
{
   vector<vector<int>> matrix = {{2, 2, -1}};
   EXPECT_EQ(solution.maxSumSubmatrix(matrix, 2), 2);
}

TEST_F(LeetCodeTest, Failure2)
{
   vector<vector<int>> matrix = {{2, 2, -1}};
   EXPECT_EQ(solution.maxSumSubmatrix(matrix, 0), -1);
}

TEST_F(LeetCodeTest, Failure3)
{
    vector<vector<int>> matrix = {
        {5, -4, -3, 4},
        {-3, -4, 4, 5},
        {5, 1, 5, -4}};
    EXPECT_EQ(solution.maxSumSubmatrix(matrix, 8), 8);
}
