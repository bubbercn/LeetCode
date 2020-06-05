#pragma once
#include "Common.h"

class Solution
{
public:
    int rangeBitwiseAnd(int m, int n)
    {
        while (n > m)
        {
            n &= (n - 1);
        }
        
        return n & m;
    }
};

void Test()
{
    Solution solution;
    assert(solution.rangeBitwiseAnd(5, 7) == 4);
    assert(solution.rangeBitwiseAnd(0, 1) == 0);
}