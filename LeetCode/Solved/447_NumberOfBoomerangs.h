#pragma once
#include "Common.h"

class Solution
{
public:
    int numberOfBoomerangs(vector<vector<int>> &points)
    {
        int result = 0;
        vector<vector<long>> distances(points.size(), vector<long>(points.size(), 0));
        for (int i = 0; i < points.size(); i++)
        {
            for (int j = 0; j < points.size(); j++)
            {
                if (i > j)
                {
                    distances[i][j] = distances[j][i];
                }
                else if (i < j)
                {
                    distances[i][j] = static_cast<long>(points[i][0] - points[j][0]) * (points[i][0] - points[j][0]) + static_cast<long>(points[i][1] - points[j][1]) * (points[i][1] - points[j][1]);
                }
            }
        }
        for (int i = 0; i < points.size(); i++)
        {
            unordered_map<int, int> lookup;
            for (int j = 0; j < points.size(); j++)
            {
                if (j == i)
                    continue;
                lookup[distances[i][j]]++;
            }
            for (auto& i : lookup)
            {
                result += i.second * (i.second - 1);
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
    vector<vector<int>> points = {
        {0, 0},
        {1, 0},
        {2, 0},
    };
    EXPECT_EQ(solution.numberOfBoomerangs(points), 2);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<vector<int>> points = {
        {1, 1},
        {2, 2},
        {3, 3},
    };
    EXPECT_EQ(solution.numberOfBoomerangs(points), 2);
}

TEST_F(LeetCodeTest, Example3)
{
    vector<vector<int>> points = {
        {1, 1},
    };
    EXPECT_EQ(solution.numberOfBoomerangs(points), 0);
}