#pragma once
#include "Common.h"

class Solution {
public:
    int mySqrt(int x)
    {
        int left = 1, right = x / 2;
        while (left <= right)
        {
            int middle = (left + right) / 2;
            int temp = middle * middle;
            if (temp == x)
            {
                return middle;
            }
            else if (temp > x)
            {
                right = middle - 1;
            }
            else
            {
                int temp = (middle + 1) * (middle + 1);
                if (temp > x)
                {
                    return middle;
                }
                else
                {
                    left = middle + 1;
                }
            }
        }
        return 0;
    }
};

void Test()
{
    Solution solution;
    assert(solution.mySqrt(4) == 2);
    assert(solution.mySqrt(8) == 2);
}
