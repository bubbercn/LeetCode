#pragma once
#include "Common.h"

struct pair_hash
{
    template <class T1, class T2>
    std::size_t operator()(const std::pair<T1, T2> &p) const
    {
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);
        return h1 ^ h2;
    }
};

class Solution
{
public:
    double minAreaFreeRect(vector<vector<int>> &points)
    {
        unordered_map<pair<int, int>, unordered_map<int, list<pair<int, int>>>, pair_hash> lookup;
        int n = points.size();
        for (int i = 0; i < n; i++)
        {
            int x1 = points[i][0];
            int y1 = points[i][1];
            for (int j = i + 1; j < n; j++)
            {
                int x2 = points[j][0];
                int y2 = points[j][1];
                pair<int, int> key1 = {x1 + x2, y1 + y2};
                int key2 = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
                lookup[key1][key2].emplace_back(i, j);
            }
        }
        double result = numeric_limits<double>::max();
        for (auto &[key1, value1] : lookup)
        {
            for (auto &[key2, value2] : value1)
            {
                if (value2.size() > 1)
                {
                    for (auto i = value2.begin(); i != value2.end(); i++)
                    {
                        int x1 = points[i->first][0];
                        int y1 = points[i->first][1];
                        int x2 = points[i->second][0];
                        int y2 = points[i->second][1];
                        auto j = i;
                        for (j++; j != value2.end(); j++)
                        {
                            int x3 = points[j->first][0];
                            int y3 = points[j->first][1];
                            long temp = static_cast<long>((x1 - x3) * (x1 - x3) + (y1 - y3) * (y1 - y3)) * ((x2 - x3) * (x2 - x3) + (y2 - y3) * (y2 - y3));
                            result = min(result, sqrt(temp));
                        }
                    }
                }
            }
        }
        return result == numeric_limits<double>::max() ? 0 : result;
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
        {1, 2},
        {2, 1},
        {1, 0},
        {0, 1},
    };
    EXPECT_EQ(solution.minAreaFreeRect(points), 2);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<vector<int>> points = {
        {0, 1},
        {2, 1},
        {1, 1},
        {1, 0},
        {2, 0},
    };
    EXPECT_EQ(solution.minAreaFreeRect(points), 1);
}

TEST_F(LeetCodeTest, Example3)
{
    vector<vector<int>> points = {
        {0, 3},
        {1, 2},
        {3, 1},
        {1, 3},
        {2, 1},
    };
    EXPECT_EQ(solution.minAreaFreeRect(points), 0);
}

TEST_F(LeetCodeTest, Failure1)
{
    vector<vector<int>> points = {
        {0, 2},
        {0, 1},
        {3, 3},
        {1, 0},
        {2, 3},
        {1, 2},
        {1, 3},
    };
    EXPECT_EQ(solution.minAreaFreeRect(points), 0);
}