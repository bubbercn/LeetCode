#pragma once
#include "Common.h"

class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        unordered_set<int> lookup;
        for (auto i : nums)
        {
            auto temp = lookup.emplace(i);
            if (!temp.second)
            {
                return true;
            }
        }
        return false;
    }
};

void Test()
{
}