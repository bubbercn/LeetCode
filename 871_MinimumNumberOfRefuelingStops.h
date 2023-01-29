#pragma once
#include "Common.h"

class Solution
{
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>> &stations)
    {
        int fuel = startFuel;
        sort(stations.begin(), stations.end(), [](const vector<int>&v1, const vector<int>& v2){
            return v1[0] < v2[0];
        });
        priority_queue<int> pq;
        int i = 0;
        int result = 0;
        while (fuel < target)
        {
            while (i < stations.size() && fuel >= stations[i][0])
            {
                pq.emplace(stations[i][1]);
                i++;
            }
            if (pq.empty())
                return -1;
            fuel += pq.top();
            pq.pop();
            result++;
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
    vector<vector<int>> stations = {};
    EXPECT_EQ(solution.minRefuelStops(1, 1, stations), 0);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<vector<int>> stations = {{10, 100}};
    EXPECT_EQ(solution.minRefuelStops(100, 1, stations), -1);
}

TEST_F(LeetCodeTest, Example3)
{
    vector<vector<int>> stations = {
        {10, 60},
        {20, 30},
        {30, 30},
        {60, 40},
    };
    EXPECT_EQ(solution.minRefuelStops(100, 10, stations), 2);
}