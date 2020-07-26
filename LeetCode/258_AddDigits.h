#pragma once
#include "Common.h"

class Solution
{
public:
    int addDigits(int num)
    {
        if (num == 0)
            return 0;
        int temp = num % 9;
        return temp ? temp : 9;
    }
};

void Test()
{
}