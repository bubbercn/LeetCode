#pragma once
#include "Common.h"

class Solution
{
public:
    int numBusesToDestination(vector<vector<int>> &routes, int source, int target)
    {
        int n = routes.size();
        unordered_map<int, unordered_set<int>> stop2Buses;
        vector<unordered_set<int>> bus2Stops(n);
        for (int i = 0; i < n; i++)
        {
            auto& route = routes[i];
            for (auto stop : route)
            {
                stop2Buses[stop].emplace(i);
                bus2Stops[i].emplace(stop);
            }
        }

        if (source == target)
            return 0;
        
        int result = 1;
        vector<bool> visited(n, false);
        list<int> cur;
        for (auto bus : stop2Buses[source])
        {
            cur.emplace_back(bus);
            visited[bus] = true;
        }
        while (!cur.empty())
        {
            list<int> next;
            for (auto bus : cur)
            {
                auto& stops = bus2Stops[bus];
                if (auto it = stops.find(target); it != stops.end())
                    return result;
                
                for (auto stop : stops)
                {
                    for (auto bus : stop2Buses[stop])
                    {
                        if (visited[bus])
                            continue;
                        
                        next.emplace_back(bus);
                        visited[bus] = true;
                    }
                }
            }
            result++;
            cur.swap(next);
        }
        return -1;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<vector<int>> routes = {
        {1, 2, 7},
        {3, 6, 7},
    };
    EXPECT_EQ(solution.numBusesToDestination(routes, 1, 6), 2);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<vector<int>> routes = {
        {7, 12},
        {4, 5, 15},
        {6},
        {15, 19},
        {9, 12, 13},
    };
    EXPECT_EQ(solution.numBusesToDestination(routes, 15, 12), -1);
}