#pragma once
#include "Common.h"

class Solution
{
public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        unordered_multimap<int, pair<int, int>> lookup;
        for (auto& time : times)
        {
            lookup.insert({time[0], {time[1], time[2]}});
        }

        vector<int> distance(n + 1, numeric_limits<int>::max());
        vector<bool> visited(n + 1, false);
        distance[k] = 0;
        queue<int> current;
        current.emplace(k);
        
        while (!current.empty())
        {
            int from = current.front();
            auto range = lookup.equal_range(from);
            for (auto it = range.first; it != range.second; it++)
            {
                auto [to, d] = it->second;
                if (distance[from] + d < distance[to])
                {
                    distance[to] = min(distance[to], distance[from] + d);
                    current.emplace(to);
                }

            }
            current.pop();
        }

        int result = *max_element(distance.begin() + 1, distance.end());
        return result == numeric_limits<int>::max() ? -1 : result;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<vector<int>> times = {
        {2, 1, 1},
        {2, 3, 1},
        {3, 4, 1},
    };
    EXPECT_EQ(solution.networkDelayTime(times, 4, 2), 2);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<vector<int>> times = {
        {1, 2, 1},
    };
    EXPECT_EQ(solution.networkDelayTime(times, 2, 1), 1);
}

TEST_F(LeetCodeTest, Example3)
{
    vector<vector<int>> times = {
        {1, 2, 1},
    };
    EXPECT_EQ(solution.networkDelayTime(times, 2, 2), -1);
}