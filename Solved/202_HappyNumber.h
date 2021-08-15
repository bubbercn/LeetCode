#pragma once
#include "Common.h"

class Solution
{
public:
    bool isHappy(int n)
    {
        unordered_set<int> visited;
        return helper(n, visited);
    }

private:
    bool helper(int n, unordered_set<int> &visited)
    {
        auto inserted = visited.emplace(n);
        if (!inserted.second)
            return false;
        int next = 0;
        while (n > 0)
        {
            int digit = n % 10;
            next += (digit * digit);
            n /= 10;
        }

        if (next == 1)
        {
            return true;
        }
        

        return helper(next, visited);
    }
};

void Test()
{
    Solution solution;
    assert(solution.isHappy(19));
}