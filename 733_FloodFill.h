#pragma once
#include "Common.h"

class Solution
{
public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
    {
        int oriColor = image[sr][sc];
        if (oriColor == newColor)
            return image;
        int m = image.size();
        int n = image[0].size();
        list<pair<int, int>> cur;
        cur.emplace_back(sr, sc);
        while (!cur.empty())
        {
            list<pair<int, int>> next;
            for (auto [r, c] : cur)
            {
                image[r][c] = newColor;
                for (auto [dx, dy] : directions)
                {
                    int x = r + dx;
                    int y = c + dy;
                    if (x >= 0 && x < m && y >= 0 && y < n && image[x][y] == oriColor)
                    {
                        next.emplace_back(x, y);
                    }
                }
            }
            cur.swap(next);
        }
        return image;
    }

private:
    inline static vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<vector<int>> image = {
        {1, 1, 1},
        {1, 1, 0},
        {1, 0, 1},
    };
    vector<vector<int>> output = {
        {2, 2, 2},
        {2, 2, 0},
        {2, 0, 1},
    };
    EXPECT_EQ(solution.floodFill(image, 1, 1, 2), output);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<vector<int>> image = {
        {0, 0, 0},
        {0, 0, 0},
    };
    vector<vector<int>> output = {
        {2, 2, 2},
        {2, 2, 2},
    };
    EXPECT_EQ(solution.floodFill(image, 0, 0, 2), output);
}