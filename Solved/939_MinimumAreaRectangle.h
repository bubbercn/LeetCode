#pragma once
#include "Common.h"

class Solution
{
public:
    int minAreaRect(vector<vector<int>> &points)
    {
        int m = points.size();
        int n = points[0].size();
        set<pair<int, int>> lookup;
        for (auto& point : points)
        {
            lookup.emplace(point[0], point[1]);
        }
        int result = numeric_limits<int>::max();
        for (auto i = lookup.begin(); i != lookup.end(); i++)
        {
            auto j = i;
            j++;
            for (; j != lookup.end(); j++)
            {
                if (j->first > i->first && j->second > i->second)
                {
                    if (lookup.find({i->first, j->second}) != lookup.end() && lookup.find({j->first, i->second}) != lookup.end())
                    {
                        result = min(result, (j->first - i->first) * (j->second - i->second));
                    }
                }
            }
        }
        return result == numeric_limits<int>::max() ? 0 : result;
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
        {1, 1},
        {1, 3},
        {3, 1},
        {3, 3},
        {2, 2},
    };
    EXPECT_EQ(solution.minAreaRect(points), 4);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<vector<int>> points = {
        {1, 1},
        {1, 3},
        {3, 1},
        {3, 3},
        {4, 1},
        {4, 3},
    };
    EXPECT_EQ(solution.minAreaRect(points), 2);
}