#pragma once
#include "Common.h"

class Solution {
public:
    string addBinary(string a, string b)
    {
        size_t aLen = a.size();
        size_t bLen = b.size();
        
        if (aLen < bLen)
        {
            a.swap(b);
            swap(aLen, bLen);
        }
        
        char add = 0;
        auto i = a.rbegin();
        for (auto j = b.rbegin(); i != a.rend() && j != b.rend(); i++, j++)
        {
            char sum = *i - '0' + *j - '0' + add;
            if (sum > 1)
            {
                add = 1;
                sum -= 2;
            }
            else
            {
                add = 0;
            }
            *i = sum + '0';
        }
        
        for (; i != a.rend(); i++)
        {
            char sum = *i - '0' + add;
            if (sum > 1)
            {
                add = 1;
                sum -= 2;
            }
            else
            {
                add = 0;
            }
            *i = sum + '0';
        }
        
        if (add == 1)
        {
            a.insert(a.begin(), '1');
        }
        
        return a;
    }
};

void Test()
{
    Solution solution;
    assert(solution.addBinary("11", "1") == "100");
    assert(solution.addBinary("1010", "1011") == "10101");
}
