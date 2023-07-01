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
    bool equationsPossible(vector<string> &equations)
    {
        int left = 0;
        int right = equations.size() - 1;
        while (left < right)
        {
            while (left < right and equations[left][1] == '=')
            {
                left++;
            }
            while (right > left and equations[right][1] == '!')
            {
                right--;
            }
            if (left < right)
            {
                swap(equations[left], equations[right]);
                left++;
                right--;
            }
            else
            {
                break;
            }
        }

        DisjointSet ds(26);
        for (auto &equation : equations)
        {
            if (equation[1] == '=')
            {
                ds.merge(equation[0] - 'a', equation[3] - 'a');
            }
            else
            {
                if (ds.find(equation[0] - 'a') == ds.find(equation[3] - 'a'))
                {
                    return false;
                }
            }
        }
        return true;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<string> equations = {"a==b", "b!=a"};
    EXPECT_EQ(solution.equationsPossible(equations), false);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<string> equations = {"b==a", "a==b"};
    EXPECT_EQ(solution.equationsPossible(equations), true);
}

TEST_F(LeetCodeTest, Failure1)
{
    vector<string> equations = {"a==b", "b!=c", "c==a"};
    EXPECT_EQ(solution.equationsPossible(equations), false);
}