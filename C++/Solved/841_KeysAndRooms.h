#pragma once
#include "Common.h"

class Solution
{
public:
    bool canVisitAllRooms(vector<vector<int>> &rooms)
    {
        int n = rooms.size();
        vector<bool> visited(n);
        list<int> keys = {0};
        visited[0] = true;
        while (not keys.empty())
        {
            list<int> next;
            for (auto key : keys)
            {
                for (auto nextKey : rooms[key])
                {
                    if (visited[nextKey])
                        continue;
                    visited[nextKey] = true;
                    next.emplace_back(nextKey);
                }
            }
            next.swap(keys);
        }
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if (visited[i])
                count++;
        }
        return count == n;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<vector<int>> rooms = {
        {1},
        {2},
        {3},
        {},
    };
    EXPECT_EQ(solution.canVisitAllRooms(rooms), true);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<vector<int>> rooms = {
        {1, 3},
        {3, 0, 1},
        {2},
        {0},
    };
    EXPECT_EQ(solution.canVisitAllRooms(rooms), false);
}