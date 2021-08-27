#pragma once
#include "Common.h"

class Solution
{
public:
    Solution()
    {
    }

    Solution(int m, int n)
    {
        this->m = m;
        this->n = n;
        reset();
    }

    vector<int> flip()
    {
        int key = rand() % last;
        int value = getValue(key);
        last--;
        if (key != last)
            lookup[key] = getValue(last);
        return {value / n, value % n % n};
    }

    void reset()
    {
        last = m * n;
        lookup.clear();
    }

private:
    unordered_map<int, int> lookup;
    int getValue(int key)
    {
        if (auto it = lookup.find(key); it != lookup.end())
        {
            return it->second;
        }
        else
        {
            return key;
        }
    }
    int m, n;
    int last;
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    Solution solution(3, 1);
    auto result = solution.flip();
    result = solution.flip();
    result = solution.flip();
    solution.reset();
    result = solution.flip();
}

TEST_F(LeetCodeTest, Example2)
{
    Solution solution(2, 2);
    solution.flip();
    solution.flip();
    solution.flip();
    solution.flip();
    solution.reset();
    solution.flip();
}

TEST_F(LeetCodeTest, Example3)
{
    Solution solution(1, 3);
    solution.flip();
    solution.flip();
    solution.flip();
    solution.reset();
    solution.flip();
}