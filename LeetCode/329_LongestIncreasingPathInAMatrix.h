#pragma once
#include "Common.h"

struct classcomp
{
    bool operator()(const tuple<int, int, int> &left, const tuple<int, int, int> &right) const
    {
        return get<2>(left) < get<2>(right);
    }
};

class Solution
{
public:
    int longestIncreasingPath(vector<vector<int>> &matrix)
    {
        if (matrix.empty())
            return 0;

        vector<vector<int>> lengthOfPath(matrix.size(), vector<int>(matrix[0].size(), 1));
        multiset<tuple<int, int, int>, classcomp> toCheck;
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[0].size(); j++)
            {
                toCheck.emplace(i, j, matrix[i][j]);
            }
        }
        int max = 1;
        for (auto &i : toCheck)
        {
            check(get<0>(i), get<1>(i), lengthOfPath, matrix, max);
        }

        return max;
    }

private:
    void check(int m, int n, vector<vector<int>> &lengthOfPath, const vector<vector<int>> &matrix, int &max)
    {
        auto helper = [&](int x, int y) {
            if (x < 0 || x >= lengthOfPath.size() || y < 0 || y >= lengthOfPath[0].size())
                return;
            if (matrix[x][y] > matrix[m][n] && lengthOfPath[m][n] + 1 > lengthOfPath[x][y])
            {
                lengthOfPath[x][y] = lengthOfPath[m][n] + 1;
                max = ::max(max, lengthOfPath[x][y]);
            }
        };
        helper(m - 1, n);
        helper(m + 1, n);
        helper(m, n - 1);
        helper(m, n + 1);
    }
};

class LeetCodeTest : public testing::Test
{
public:
    static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<vector<int>> nums = {
        {9, 9, 4},
        {6, 6, 8},
        {2, 1, 1}};
    EXPECT_EQ(solution.longestIncreasingPath(nums), 4);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<vector<int>> nums = {
        {3, 4, 5},
        {3, 2, 6},
        {2, 2, 1}};
    EXPECT_EQ(solution.longestIncreasingPath(nums), 4);
}
