#pragma once
#include "Common.h"

class Solution
{
public:
    int reachableNodes(vector<vector<int>> &edges, int maxMoves, int n)
    {
        vector<vector<int>> lookup(n, vector<int>(n, numeric_limits<int>::max()));
        for (auto &edge : edges)
        {
            lookup[edge[0]][edge[1]] = edge[2] + 1;
            lookup[edge[1]][edge[0]] = edge[2] + 1;
        }
        for (int i = 0; i < n; i++)
        {
            lookup[i][i] = 0;
        }
        vector<int> minDistance(n, numeric_limits<int>::max());
        for (int i = 0; i < n; i++)
        {
            minDistance[i] = lookup[0][i];
        }
        unordered_set<int> visited;
        visited.emplace(0);
        auto cmp = [&minDistance](int i1, int i2) {
            return i1 < i2;
        };
        unordered_set<int> unVisited;
        for (int i = 1; i < n; i++)
        {
            unVisited.emplace(i);
        }
        
        while (!unVisited.empty())
        {
            int v = 0;
            int m = numeric_limits<int>::max();
            for (auto to : unVisited)
            {
                if (minDistance[to] < m)
                {
                    m = minDistance[to];
                    v = to;
                }
            }
            if (m > maxMoves)
                break;
            
            for (int to = 0; to < n; to++)
            {
                if (lookup[v][to] == numeric_limits<int>::max())
                    continue;
                minDistance[to] = min(minDistance[to], minDistance[v] + lookup[v][to]);
            }
            unVisited.erase(v);
            visited.emplace(v);
        }

        int result = 0;
        vector<vector<int>> go(n, vector<int>(n));
        for (int i = 0; i < n; i++)
        {
            if (minDistance[i] <= maxMoves)
            {
                result++;
                for (int j = 0; j < n; j++)
                {
                    if (j == i)
                        continue;
                    go[i][j] = min(maxMoves - minDistance[i], lookup[i][j]);
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (lookup[i][j] == numeric_limits<int>::max())
                    continue;
                int temp = go[i][j] + go[j][i];
                if (temp != 0)
                {
                    result += min(temp, lookup[i][j] - 1);
                }
            }
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