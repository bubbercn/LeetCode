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
    int largestComponentSize(vector<int> &nums)
    {
        int n = nums.size();
        DisjointSet ds(n);
        unordered_map<int, int> groups;
        for (int i = 0; i < n; i++)
        {
            auto factors = getFactors(nums[i]);
            for (auto factor : factors)
            {
                if (auto [it, inserted] = groups.emplace(factor, i); !inserted)
                {
                    ds.merge(it->second, i);
                }
            }
        }
        int result = 0;
        unordered_map<int, int> count;
        for (int i = 0; i < n; i++)
        {
            int temp = ++count[ds.find(i)];
            result = max(result, temp);
        }
        return result;
    }
    inline static unordered_map<int, list<int>> lookup;

private:
    static list<int> getFactors(int n)
    {
        if (auto it = lookup.find(n); it != lookup.end())
            return it->second;

        list<int> result;
        result.emplace_back(n);
        for (int i = 2; i * i <= n; i++)
        {
            if (n % i == 0)
            {
                result.emplace_back(i);
                auto temp = getFactors(n / i);
                result.insert(result.end(), temp.begin(), temp.end());
                break;
            }
        }
        lookup.emplace(n, result);
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
    vector<int> nums = {4, 6, 15, 35};
    EXPECT_EQ(solution.largestComponentSize(nums), 4);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> nums = {20, 50, 9, 63};
    EXPECT_EQ(solution.largestComponentSize(nums), 2);
}

TEST_F(LeetCodeTest, Example3)
{
    vector<int> nums = {2, 3, 6, 7, 4, 12, 21, 39};
    EXPECT_EQ(solution.largestComponentSize(nums), 8);
}