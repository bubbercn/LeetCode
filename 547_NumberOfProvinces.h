#pragma once
#include "Common.h"

class Solution
{
public:
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        DisjointSet ds(isConnected.size());
        for (int i = 0; i < isConnected.size(); i++)
        {
            for (int j = i + 1; j < isConnected.size(); j++)
            {
                if (isConnected[i][j] == 1)
                {
                    ds.merge(i, j);
                }
            }
        }
        return ds.size();
    }

private:
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
            parent[find(index1)] = find(index2);
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
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<vector<int>> isConnected = {
        {1, 1, 0},
        {1, 1, 0},
        {0, 0, 1},
    };
    EXPECT_EQ(solution.findCircleNum(isConnected), 2);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<vector<int>> isConnected = {
        {1, 0, 0},
        {0, 1, 0},
        {0, 0, 1},
    };
    EXPECT_EQ(solution.findCircleNum(isConnected), 3);
}