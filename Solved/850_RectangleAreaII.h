#pragma once
#include "Common.h"

class Solution
{
public:
    int rectangleArea(vector<vector<int>> &rectangles)
    {
        auto lookup = process(rectangles);
        long result = 0;
        multiset<pair<int, int>> heights;
        long begin = -1;
        for (auto &[key, value] : lookup)
        {
            auto [bottom, top, in] = value;
            if (begin != -1)
            {
                long height = getHeight(heights);
                result += (key - begin) * height;
                result %= MOD;
            }
            if (in)
            {
                heights.emplace(bottom, top);
            }
            else
            {
                auto it = heights.find(make_pair(bottom, top));
                heights.erase(it);
            }
            begin = key;
        }
        return result;
    }

private:
    multimap<int, tuple<int, int, bool>> process(vector<vector<int>> &rectangles)
    {
        multimap<int, tuple<int, int, bool>> result;
        for (auto &rectangle : rectangles)
        {
            int left = rectangle[0];
            int bottom = rectangle[1];
            int right = rectangle[2];
            int top = rectangle[3];
            result.insert({left, {bottom, top, true}});
            result.insert({right, {bottom, top, false}});
        }
        return result;
    }

    int getHeight(multiset<pair<int, int>> &heights)
    {
        map<int, int> heightMap;
        for (auto [bottom, top] : heights)
        {
            auto begin = heightMap.lower_bound(bottom);
            if (begin != heightMap.begin())
                begin--;
            for (auto it = begin; it != heightMap.end() && it->first <= top;)
            {
                if (overlap(it->first, it->second, bottom, top))
                {
                    bottom = min(bottom, it->first);
                    top = max(top, it->second);
                    it = heightMap.erase(it);
                }
                else
                {
                    if (it->first > top)
                        break;
                    it++;
                }
            }
            heightMap.emplace(bottom, top);
        }
        int result = 0;
        for (auto [bottom, up] : heightMap)
        {
            result += up - bottom;
        }
        return result;
    }

    bool overlap(int begin1, int end1, int begin2, int end2)
    {
        return !(end1 < begin2 || end2 < begin1);
    }

    static constexpr int MOD = 1000000007;
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<vector<int>> rectangles = {
        {0, 0, 2, 2},
        {1, 0, 2, 3},
        {1, 0, 3, 1},
    };
    EXPECT_EQ(solution.rectangleArea(rectangles), 6);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<vector<int>> rectangles = {
        {0, 0, 1000000000, 1000000000},
    };
    EXPECT_EQ(solution.rectangleArea(rectangles), 49);
}

TEST_F(LeetCodeTest, Failure1)
{
    vector<vector<int>> rectangles = {
        {0, 0, 2, 2},
        {1, 1, 3, 3},
    };
    EXPECT_EQ(solution.rectangleArea(rectangles), 7);
}

TEST_F(LeetCodeTest, Failure2)
{
    vector<vector<int>> rectangles = {
        {0, 0, 3, 3},
        {2, 0, 5, 3},
        {1, 1, 4, 4},
    };
    EXPECT_EQ(solution.rectangleArea(rectangles), 18);
}

TEST_F(LeetCodeTest, Failure3)
{
    vector<vector<int>> rectangles = {
        {49, 40, 62, 100},
        {11, 83, 31, 99},
        {19, 39, 30, 99},
    };
    EXPECT_EQ(solution.rectangleArea(rectangles), 1584);
}