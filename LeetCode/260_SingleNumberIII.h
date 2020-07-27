#pragma once
#include "Common.h"

class Solution
{
public:
    vector<int> singleNumber(vector<int> &nums)
    {
        int mask = 0;
        for (auto i : nums)
        {
            mask ^= i;
        }
        int diff = mask & (-mask);
        int x = 0;
        for (auto i : nums)
        {
            if (i & diff)
            {
                x ^= i;
            }
        }
        return {x, x ^ mask};
    }
};

void Test()
{
}