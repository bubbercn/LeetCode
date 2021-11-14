#pragma once
#include "Common.h"

class Solution
{
public:
    vector<vector<int>> outerTrees(vector<vector<int>> &trees)
    {
        set<Point> vertexSet2;
        for (auto &tree : trees)
        {
            vertexSet2.emplace(tree[0], tree[1]);
        }

        Point cv = *vertexSet2.begin();
        Point pv = {cv.first, cv.second + 1};
        set<Point> vertexSet1;
        vertexSet1.emplace(cv);
        while (true)
        {
            list<Point> points = helper(pv, cv, vertexSet2);
            pv = cv;
            cv = points.front();
            bool stop = false;
            for (auto &point : points)
            {
                if (vertexSet1.emplace(point).second == false)
                    stop = true;
            }
            if (stop)
                break;
        }
        vector<vector<int>> result;
        for (auto &[x, y] : vertexSet1)
        {
            result.push_back({x, y});
        }
        return result;
    }

private:
    using Point = pair<int, int>;
    list<Point> helper(const Point &pv, const Point &cv, const set<Point> &vertexSet)
    {
        list<Point> result;
        double minCos = 1;
        for (auto &v : vertexSet)
        {
            if (v == cv)
                continue;

            double cos = Cos(cv, pv, v);
            if (fabs(cos - minCos) < 0.0000000001)
            {
                if (distance2(cv, result.front()) > distance2(cv, v))
                {
                    result.emplace_back(v);
                }
                else
                {
                    result.emplace_front(v);
                }
            }
            else if (cos < minCos)
            {
                minCos = cos;
                result.clear();
                result.emplace_back(v);
            }
        }
        return result;
    }
    double Cos(const Point &v1, const Point &v2, const Point &v3)
    {
        double x1 = distance2(v1, v2) + distance2(v1, v3) - distance2(v2, v3);
        double x2 = 2 * distance(v1, v2) * distance(v1, v3);
        return x1 / x2;
    }
    double distance(const Point &v1, const Point &v2)
    {
        return sqrt(distance2(v1, v2));
    }
    double distance2(const Point &v1, const Point &v2)
    {
        return pow(v2.first - v1.first, 2) + pow(v2.second - v1.second, 2);
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<vector<int>> trees = {
        {1, 1},
        {2, 2},
        {2, 0},
        {2, 4},
        {3, 3},
        {4, 2},
    };
    vector<vector<int>> output = {
        {1, 1},
        {2, 0},
        {3, 3},
        {2, 4},
        {4, 2},
    };
    EXPECT_EQ(solution.outerTrees(trees), output);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<vector<int>> trees = {
        {1, 2},
        {2, 2},
        {4, 2},
    };
    vector<vector<int>> output = {
        {4, 2},
        {2, 2},
        {1, 2},
    };
    EXPECT_EQ(solution.outerTrees(trees), output);
}