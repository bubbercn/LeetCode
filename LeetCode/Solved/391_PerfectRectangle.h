#pragma once
#include "Common.h"

class Solution
{
public:
    bool isRectangleCover(vector<vector<int>> &rectangles)
    {
        if (rectangles.empty())
            return false;

        pair<int, int> bottomLeft = {INT_MAX, INT_MAX};
        pair<int, int> topRight = {INT_MIN, INT_MIN};
        int area = 0;
        map<pair<int, int>, int> pointLookup;
        for (auto &rectangle : rectangles)
        {
            int &bottom = rectangle[1];
            int &left = rectangle[0];
            int &top = rectangle[3];
            int &right = rectangle[2];
            bottomLeft.first = min(bottomLeft.first, bottom);
            bottomLeft.second = min(bottomLeft.second, left);
            topRight.first = max(topRight.first, top);
            topRight.second = max(topRight.second, right);
            area += (top - bottom) * (right - left);
            pointLookup[{bottom, left}]++;
            pointLookup[{bottom, right}]++;
            pointLookup[{top, left}]++;
            pointLookup[{top, right}]++;
        }

        if (area != (topRight.first - bottomLeft.first) * (topRight.second - bottomLeft.second))
            return false;
        
        pointLookup[{bottomLeft.first, bottomLeft.second}]++;
        pointLookup[{bottomLeft.first, topRight.second}]++;
        pointLookup[{topRight.first, topRight.second}]++;
        pointLookup[{topRight.first, bottomLeft.second}]++;

        for (auto& i : pointLookup)
        {
            if (i.second & 1)
                return false;
        }

        return true;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
    inline static vector<vector<int>> rectangles;
};

TEST_F(LeetCodeTest, Example1)
{
    rectangles = {
        {1, 1, 3, 3},
        {3, 1, 4, 2},
        {3, 2, 4, 4},
        {1, 3, 2, 4},
        {2, 3, 3, 4},
    };
    EXPECT_EQ(solution.isRectangleCover(rectangles), true);
}

TEST_F(LeetCodeTest, Example2)
{
    rectangles = {
        {1, 1, 2, 3},
        {1, 3, 2, 4},
        {3, 1, 4, 2},
        {3, 2, 4, 4},
    };
    EXPECT_EQ(solution.isRectangleCover(rectangles), false);
}

TEST_F(LeetCodeTest, Example3)
{
    rectangles = {
        {1, 1, 3, 3},
        {3, 1, 4, 2},
        {1, 3, 2, 4},
        {3, 2, 4, 4},
    };
    EXPECT_EQ(solution.isRectangleCover(rectangles), false);
}

TEST_F(LeetCodeTest, Example4)
{
    rectangles = {
        {1, 1, 3, 3},
        {3, 1, 4, 2},
        {1, 3, 2, 4},
        {2, 2, 4, 4},
    };
    EXPECT_EQ(solution.isRectangleCover(rectangles), false);
}

TEST_F(LeetCodeTest, Failure1)
{
    rectangles = {
        {1, 1, 2, 2},
        {0, 1, 1, 2},
        {1, 0, 2, 1},
        {0, 2, 3, 3},
        {2, 0, 3, 3},
    };
    EXPECT_EQ(solution.isRectangleCover(rectangles), false);
}