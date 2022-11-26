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
    int numSimilarGroups(vector<string> &strs)
    {
        int n = strs.size();
        DisjointSet dsj(n);
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int t1 = dsj.find(i);
                int t2 = dsj.find(j);
                if (t1 == t2)
                    continue;
                if (helper(strs[i], strs[j]))
                    dsj.merge(t1, t2);
            }
        }
        return dsj.size();
    }

    bool helper(string_view s1, string_view s2)
    {
        int result = 0;
        for (int i = 0; i < s1.length(); i++)
        {
            if (s1[i] != s2[i])
                result++;
        }
        return result == 0 || result == 2;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<string> strs = {"tars", "rats", "arts", "star"};
    EXPECT_EQ(solution.numSimilarGroups(strs), 2);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<string> strs = {"omv", "ovm"};
    EXPECT_EQ(solution.numSimilarGroups(strs), 1);
}