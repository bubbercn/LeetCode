#pragma once
#include "Common.h"

class Solution {
public:
    int climbStairs(int n)
    {
        assert(n > 0);
        if (n == 1)
        {
            return 1;
        }
        else if (n == 2)
        {
            return 2;
        }
        else
        {
            int a = 1, b = 2, c = 0;
            while (n > 2)
            {
                c = a + b;
                a = b;
                b = c;
                n--;
            }
            return c;
        }
    }
};

void Test()
{
    Solution solution;
    assert(solution.climbStairs(2) == 2);
    assert(solution.climbStairs(3) == 3);
}
