#pragma once
#include "Common.h"

bool isBadVersion(int version);

class Solution
{
public:
    int firstBadVersion(int n)
    {
        long low = 1;
        long high = n;
        while (low <= high)
        {
            long middle = (low + high) / 2;
            if (!isBadVersion(middle))
            {
                low = middle + 1;
            }
            else if (!isBadVersion(middle - 1))
            {
                return middle;
            }
            else
            {
                high = middle - 1;
            }
        }
        return 0;
    }
};

void Test()
{
}