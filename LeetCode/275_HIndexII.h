#pragma once
#include "Common.h"

class Solution
{
public:
    int hIndex(vector<int> &citations)
    {
        int high = citations.size();
        int low = 1;
        while (low <= high)
        {
            int middle = (low + high) / 2;
            if (citations[middle - 1] == middle)
            {
                return middle;
            }
            else if (citations[middle - 1] < middle)
            {
                low = middle + 1;
            }
            else
            {
                high = middle - 1;
            }
        }
        return -1;
    }
};

void Test()
{
}