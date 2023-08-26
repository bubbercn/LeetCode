#pragma once
#include "Common.h"

class Solution {
public:
    string convertToTitle(int n) {
        stack<int> digits;
        while (n > 0)
        {
            n--;
            digits.emplace(n % 26);
            n /= 26;
        }
        string result;
        result.reserve(digits.size());
        while (!digits.empty())
        {
            int digit = digits.top();
            digits.pop();
            result += (digit + 'A'); 
        }
        return result;
    }
};

void Test()
{
    Solution solution;
    assert(solution.convertToTitle(26) == "Z");
    assert(solution.convertToTitle(701) == "ZY");
}