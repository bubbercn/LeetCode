#pragma once
#include "Common.h"

class Solution
{
public:
    int countDigitOne(int n)
    {
        int result = 0;
        long long base = 1;
        int count = 0;

        do
        {
            count = n / (base * 10);
            result += count * base;
            int r = n - count * base * 10;
            result += min(r - base >= 0 ? r - base + 1 : 0, base);
            base *= 10;
        } while (count > 0);

        return result;
    }
};

void Test()
{
    Solution solution;
    // cout << solution.countDigitOne(11) << endl;
    for (int i = 0; i < 100; i++)
    {
        cout << i << "->" << solution.countDigitOne(i) << endl;
    }
}