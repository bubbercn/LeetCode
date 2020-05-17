#pragma once
#include "Common.h"

class Solution {
public:
    int titleToNumber(string s) 
    {
        stack<int> digits;
        for (auto c : s)
        {
            digits.emplace(c - 'A' + 1);
        }
        int result = 0;
        int base = 1;
        while (!digits.empty())
        {
            result += digits.top() * base;
            digits.pop();
            base *= 26;
        }
        return result;
    }
};

void Test()
{
    Solution solution;
    assert(solution.titleToNumber("A") == 1);
    assert(solution.titleToNumber("AB") == 28);
    assert(solution.titleToNumber("ZY") == 701);
}