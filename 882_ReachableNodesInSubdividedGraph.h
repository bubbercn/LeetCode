#pragma once
#include "Common.h"

class Solution
{
public:
    int reachableNodes(vector<vector<int>> &edges, int maxMoves, int n)
    {
        vector<unordered_map<int, int>> lookup(n);
        for (auto &edge : edges)
        {
            lookup[edge[0]][edge[1]] = edge[2] + 1;
            lookup[edge[1]][edge[0]] = edge[2] + 1;
        }
        vector<int> minDistance(n, numeric_limits<int>::max());
        minDistance[0] = 0;
        for (auto [to, distance] : lookup[0])
        {
            minDistance[to] = lookup[0][to];
        }

        unordered_set<int> visited;
        visited.emplace(0);
        auto cmp = [](pair<int, int> &v1, pair<int, int> &v2)
        {
            return v1.second > v2.second;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> unVisited(cmp);
        for (int i = 1; i < n; i++)
        {
            unVisited.emplace(i, minDistance[i]);
        }
        while (!unVisited.empty())
        {
            auto [v, m] = unVisited.top();
            if (m > maxMoves)
                break;

            unVisited.pop();
            if (visited.count(v) != 0)
                continue;

            for (auto [to, distance] : lookup[v])
            {
                if (minDistance[v] + distance < minDistance[to])
                {
                    minDistance[to] = minDistance[v] + distance;
                    if (visited.count(to) == 0)
                    {
                        unVisited.emplace(to, minDistance[to]);
                    }
                }
            }
            visited.emplace(v);
        }

        int result = 0;
        vector<vector<int>> go(n, vector<int>(n));
        for (int i = 0; i < n; i++)
        {
            if (visited.count(i) == 0)
                continue;

            result++;
            for (auto [to, distance] : lookup[i])
            {
                go[i][to] = min(maxMoves - minDistance[i], lookup[i][to]);
            }
        }

        for (auto &edge : edges)
        {
            int from = edge[0];
            int to = edge[1];
            int temp = go[from][to] + go[to][from];
            result += min(temp, edge[2]);

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
    vector<vector<int>> edges = {
        {0, 1, 10},
        {0, 2, 1},
        {1, 2, 2},
    };
    EXPECT_EQ(solution.reachableNodes(edges, 6, 3), 13);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<vector<int>> edges = {
        {0, 1, 4},
        {1, 2, 6},
        {0, 2, 8},
        {1, 3, 1},
    };
    EXPECT_EQ(solution.reachableNodes(edges, 10, 4), 23);
}

TEST_F(LeetCodeTest, Example3)
{
    vector<vector<int>> edges = {
        {1, 2, 4},
        {1, 4, 5},
        {1, 3, 1},
        {2, 3, 4},
        {3, 4, 5},
    };
    EXPECT_EQ(solution.reachableNodes(edges, 17, 5), 1);
}

TEST_F(LeetCodeTest, Failure1)
{
    vector<vector<int>> edges = {
        {2, 4, 2},
        {3, 4, 5},
        {2, 3, 1},
        {0, 2, 1},
        {0, 3, 5},
    };
    EXPECT_EQ(solution.reachableNodes(edges, 14, 5), 18);
}

TEST_F(LeetCodeTest, Failure2)
{
    vector<vector<int>> edges = {
        {1, 3, 23},
        {3, 5, 19},
        {3, 6, 17},
        {1, 5, 14},
        {6, 7, 20},
        {1, 4, 10},
        {1, 6, 0},
        {3, 4, 20},
        {1, 7, 4},
        {0, 4, 10},
        {0, 7, 9},
        {2, 3, 3},
        {3, 7, 9},
        {5, 7, 4},
        {4, 5, 16},
        {0, 1, 16},
        {2, 6, 0},
        {4, 7, 11},
        {2, 5, 14},
        {5, 6, 22},
        {4, 6, 12},
        {0, 6, 2},
        {0, 2, 1},
        {2, 4, 22},
        {2, 7, 20},
    };
    EXPECT_EQ(solution.reachableNodes(edges, 19, 8), 301);
}