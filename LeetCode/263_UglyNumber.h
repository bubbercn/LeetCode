#pragma once
#include "Common.h"

class Solution
{
public:
    bool isUgly(int num)
    {
        if (num <= 0)
            return false;
        num = helper(num, 2);
        if (num == 1)
            return true;
        num = helper(num, 3);
        if (num == 1)
            return true;
        num = helper(num, 5);
        if (num == 1)
            return true;
        else
            return false;
    }
private:
    int helper(int num, int divisor)
    {
        while (num % divisor == 0)
        {
            num /= divisor;
        }
        return num;
    }
};

void Test()
{
}