#pragma once
#include "Common.h"

class Solution
{
public:
    int reachableNodes(vector<vector<int>> &edges, int maxMoves, int n)
    {
        unordered_map<int, unordered_map<int, int>> lookup;
        for (auto &edge : edges)
        {
            lookup[edge[0]].emplace(edge[1], edge[2] + 1);
            lookup[edge[1]].emplace(edge[0], edge[2] + 1);
        }
        vector<vector<int>> visited(n, vector<int>(n));
        visited[0][0] = 1;
        map<int, int, std::greater<int>> next;
        next.emplace(maxMoves, 0);
        while (!next.empty())
        {
            map<int, int, std::greater<int>> temp;
            for (auto [left, from] : next)
            {
                if (auto it = lookup.find(from); it != lookup.end())
                {
                    for (auto [to, distance] : it->second)
                    {
                        if (visited[to][from] >= distance)
                           continue;

                        if (left >= distance)
                        {
                            visited[from][to] = distance;
                            visited[to][to] = 1;
                            temp.emplace(left - distance, to);
                        }
                        else
                        {
                            visited[from][to] = max(left, visited[from][to]);
                        }
                    }
                }
            }
            next.swap(temp);
        }
        int result = 0;
        for (int i = 0; i < n; i++)
        {
            result += visited[i][i];
            for (int j = i + 1; j < n; j++)
            {
                int temp = visited[i][j] + visited[j][i];
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