#pragma once
#include "Common.h"

class Solution {
public:
    double myPow(double x, int n) {
        if (n < 0)
        {
            size_t temp = n;
            return powerInternal(1 / x, -temp);
        }
        else
        {
            return powerInternal(x, n);
        }
    }
    
private:
    double powerInternal(double x, size_t n)
    {
        if (n == 0)
        {
            return 1;
        }
        
        if (n == 1)
        {
            return x;
        }
        
        if (n == 2)
        {
            return x * x;
        }
        
        double result = 1;
        if (n % 2 == 0)
        {
            return powerInternal(powerInternal(x, n / 2), 2);
        }
        else
        {
            return powerInternal(powerInternal(x, n / 2), 2) * x;
        }
        
        return result;
    }
};

void Test()
{
    Solution solution;
    cout << solution.myPow(2, 10) << endl;
    cout << solution.myPow(2.1, 3) << endl;
    cout << solution.myPow(2, -2) << endl;
    cout << solution.myPow(1, -2147483648) << endl;
}
