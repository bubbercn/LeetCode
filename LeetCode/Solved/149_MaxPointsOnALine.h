#pragma once
#include "Common.h"

struct pair_hash
{
    template<class T1, class T2>
    std::size_t operator() (const std::pair<T1, T2>& p) const
    {
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);
        return h1 ^ h2;
    }
};

class Solution
{
public:
    int maxPoints(vector<vector<int>>& points)
    {
        if (points.empty())
            return 0;
        
        size_t maxPointCount = 0;
        unordered_map<pair<long double, long double>, unordered_set<size_t>, pair_hash> lines;
        unordered_map<pair<int, int>, unordered_set<size_t>, pair_hash> pointsSet;
        for (size_t i = 0; i < points.size(); i++)
        {
            pointsSet[make_pair(points[i][0], points[i][1])].insert(i);
        }
        
        if (pointsSet.size() == 1)
            return static_cast<int>(pointsSet.begin()->second.size());
        
        int m = 0;
        for (auto i = pointsSet.begin(); i != pointsSet.end(); i++, m++)
        {
            int n = 0;
            for (auto j = pointsSet.begin(); j != pointsSet.end(); j++, n++)
            {
                if (m >= n)
                    continue;
                auto& temp = lines[getLine(i->first.first, i->first.second, j->first.first, j->first.second)];
                temp.insert(i->second.begin(), i->second.end());
                temp.insert(j->second.begin(), j->second.end());
                maxPointCount = max(maxPointCount, temp.size());
            }
        }
        
        return static_cast<int>(maxPointCount);
    }
private:
    pair<long double, long double> getLine(int x1, int y1, int x2, int y2)
    {
        if (x1 == x2)
        {
            return {numeric_limits<long double>::max(), x1};
        }
        long double a = (static_cast<long double>(y2) - y1) / (static_cast<long double>(x2) - x1);
        long double b = y1 - a * x1;
        return {a, b};
    }
};

void Test()
{
    Solution solution;
    vector<vector<int>> points;
    
    points = {{1,1},{2,2},{3,3}};
    assert(solution.maxPoints(points) == 3);

    points = {{1,1},{3,2},{5,3},{4,1},{2,3},{1,4}};
    assert(solution.maxPoints(points) == 4);

    points = {};
    assert(solution.maxPoints(points) == 0);

    points = {{1,1}};
    assert(solution.maxPoints(points) == 1);

    points = {{0,0},{1,1},{0,0}};
    assert(solution.maxPoints(points) == 3);

    points = {{0,-1},{0,3},{0,-4},{0,-2},{0,-4},{0,0},{0,0},{0,1},{0,-2},{0,4}};
    assert(solution.maxPoints(points) == 10);
    
    points = {{0,0},{94911151,94911150},{94911152,94911151}};
    assert(solution.maxPoints(points) == 2);
}
