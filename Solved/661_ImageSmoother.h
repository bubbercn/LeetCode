#pragma once
#include "Common.h"

class Solution
{
public:
    vector<vector<int>> imageSmoother(vector<vector<int>> &img)
    {
        int m = img.size();
        int n = img[0].size();
        vector<vector<int>> result(m, vector<int>(n));
        auto smooth = [&](int x, int y)
        {
            static const vector<int> offsetX = {-1, -1, -1, 0, 0, 0, 1, 1, 1};
            static const vector<int> offsetY = {-1, 0, 1, -1, 0, 1, -1, 0, 1};
            int sum = 0;
            int count = 0;
            for (int i = 0; i < offsetX.size(); i++)
            {
                int row = x + offsetX[i];
                int column = y + offsetY[i];
                if (row < 0 || row >= m || column < 0 || column >= n)
                    continue;
                sum += img[row][column];
                count++;
            }
            return sum / count;
        };
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                result[i][j] = smooth(i, j);
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
    vector<vector<int>> img = {
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1},
    };
    vector<vector<int>> output = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0},
    };
    EXPECT_EQ(solution.imageSmoother(img), output);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<vector<int>> img = {
        {100, 200, 100},
        {200, 50, 200},
        {100, 200, 100},
    };
    vector<vector<int>> output = {
        {137, 141, 137},
        {141, 138, 141},
        {137, 141, 137},
    };
    EXPECT_EQ(solution.imageSmoother(img), output);
}