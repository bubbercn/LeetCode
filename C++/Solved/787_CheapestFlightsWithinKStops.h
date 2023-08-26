#pragma once
#include "Common.h"

class Solution
{
public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
    {
        unordered_map<int, unordered_map<int, int>> flight2Price;
        for (auto &flight : flights)
        {
            flight2Price[flight[0]][flight[1]] = flight[2];
        }
        vector<int> prices(n, numeric_limits<int>::max());
        prices[src] = 0;
        int stops = 0;
        list<pair<int, int>> cur;
        cur.emplace_back(src, 0); 
        while (stops <= k && !cur.empty())
        {
            list<pair<int, int>> next;
            for (auto [from, distance] : cur)
            {
                if (auto it = flight2Price.find(from); it != flight2Price.end())
                {
                    for (auto &[toNode, price] : it->second)
                    {
                        if (prices[toNode] > distance + price)
                        {
                            prices[toNode] = distance + price;
                            next.emplace_back(toNode, prices[toNode]);
                        }
                    }
                }
            }
            cur.swap(next);
            stops++;
        }
        return prices[dst] == numeric_limits<int>::max() ? -1 : prices[dst];
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<vector<int>> flights = {
        {0, 1, 100},
        {1, 2, 100},
        {2, 0, 100},
        {1, 3, 600},
        {2, 3, 200},
    };
    EXPECT_EQ(solution.findCheapestPrice(4, flights, 0, 3, 1), 700);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<vector<int>> flights = {
        {0, 1, 100},
        {1, 2, 100},
        {0, 2, 500},
    };
    EXPECT_EQ(solution.findCheapestPrice(3, flights, 0, 2, 1), 200);
}

TEST_F(LeetCodeTest, Example3)
{
    vector<vector<int>> flights = {
        {0, 1, 100},
        {1, 2, 100},
        {0, 2, 500},
    };
    EXPECT_EQ(solution.findCheapestPrice(3, flights, 0, 2, 0), 500);
}

TEST_F(LeetCodeTest, Failure1)
{
    vector<vector<int>> flights = {
        {0, 1, 1},
        {0, 2, 5},
        {1, 2, 1},
        {2, 3, 1},
    };
    EXPECT_EQ(solution.findCheapestPrice(4, flights, 0, 3, 1), 6);
}