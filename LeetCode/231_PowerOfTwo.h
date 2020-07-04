#pragma once
#include "Common.h"

class Solution
{
public:
    bool isPowerOfTwo(int n)
    {
        if (n <= 0)
            return false;
        
        if (n == 1)
            return true;
        
        while (n > 1)
        {
            if (n & 1)
                return false;
            
            n >>= 1;
        }
        return true;
    }
};

void Test()
{
    Solution solution;

    assert(solution.isPowerOfTwo(1));
    assert(solution.isPowerOfTwo(16));
    assert(!solution.isPowerOfTwo(218));
}