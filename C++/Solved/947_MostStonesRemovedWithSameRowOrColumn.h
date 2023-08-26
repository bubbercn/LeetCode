#pragma once
#include "Common.h"

class DisjointSet
{
private:
    std::vector<int> parent;

public:
    DisjointSet(int size) : parent(size)
    {
        for (int i = 0; i < size; ++i)
        {
            parent[i] = i;
        }
    }
    int find(int index) const
    {
        return parent[index] == index ? index : find(parent[index]);
    }
    void merge(int index1, int index2)
    {
        parent[find(index2)] = find(index1);
    }
    int size() const
    {
        int size = 0;
        for (int i = 0; i < parent.size(); ++i)
        {
            if (parent[i] == i)
            {
                size++;
            }
        }
        return size;
    }
};

class Solution
{
public:
    int removeStones(vector<vector<int>> &stones)
    {
        int n = stones.size();
        DisjointSet ds(n);
        unordered_map<int, int> xLookup;
        unordered_map<int, int> yLookup;
        for (int i = 0; i < n; i++)
        {
            int x = stones[i][0];
            int y = stones[i][1];
            if (auto [it, inserted] = xLookup.emplace(x, i); !inserted)
            {
                ds.merge(i, it->second);
            }
            if (auto [it, inserted] = yLookup.emplace(y, i); !inserted)
            {
                ds.merge(i, it->second);
            }
        }
        return n - ds.size();
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<vector<int>> stones = {
        {0, 0},
        {0, 1},
        {1, 0},
        {1, 2},
        {2, 1},
        {2, 2},
    };
    EXPECT_EQ(solution.removeStones(stones), 5);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<vector<int>> stones = {
        {0, 0},
        {0, 2},
        {1, 1},
        {2, 0},
        {2, 2},
    };
    EXPECT_EQ(solution.removeStones(stones), 3);
}

TEST_F(LeetCodeTest, Example3)
{
    vector<vector<int>> stones = {
        {0, 0},
    };
    EXPECT_EQ(solution.removeStones(stones), 0);
}