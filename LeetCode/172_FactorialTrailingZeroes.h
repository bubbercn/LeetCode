#pragma once
#include "Common.h"

class Solution {
public:
    int trailingZeroes(int n) 
    {
        int result = 0;
        long long x = 5;
        int temp = 0;
        while ((temp = n / x) > 0)
        {
            result += temp;
            x *= 5;
        }
        return result;
    }
};

void Test()
{

}