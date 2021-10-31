#pragma once
#include "Common.h"

class Solution
{
public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
    {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> result(m, vector<int>(n, numeric_limits<int>::max()));
        set<pair<int, int>> next;


        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (mat[i][j] == 0)
                {
                    result[i][j] = 0;
                    next.emplace(i, j);
                }
            }
        }

        int distance = 1;
        while (!next.empty())
        {
            set<pair<int, int>> current;
            current.swap(next);
            for (auto [i, j] : current)
            {
                for (int k = 0; k < 4; k++)
                {
                    int x = i + indexes[k].first;
                    int y = j + indexes[k].second;
                    if (x >= 0 && x < m && y >= 0 && y < n && result[x][y] == numeric_limits<int>::max())
                    {
                        result[x][y] = distance;
                        next.emplace(x, y);
                    }
                }
            }
            distance++;
        }

        return result;
    }

private:
    inline static vector<pair<int, int>> indexes = {
        {-1, 0},
        {0, -1},
        {0, 1},
        {1, 0},
    };
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