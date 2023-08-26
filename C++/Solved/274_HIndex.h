#pragma once
#include "Common.h"

class Solution
{
public:
    int hIndex(vector<int> &citations)
    {
        sort(citations.begin(), citations.end());
        int h = citations.size();
        for (auto i : citations)
        {
            if (i < h)
                h--;
        }
        return h;
    }
};

void Test()
{
}