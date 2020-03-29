#pragma once
#include "Common.h"

class Solution 
{
public:
    int numDecodings(string s) 
    {
        if (s.empty())
            return 0;

        vector<int> result(s.length() + 1);
        result[0] = 1;

        if (s[0] == '0')
            return 0;
        result[1] = 1;

        for (int i = 2; i <= s.length(); i++)
        {
            result[i] = s[i - 1] == '0' ? 0 : result[i -1];
            if (s[i -2] == '1' || (s[i -2] == '2' && s[i -1] <= '6'))
            {
                result[i] += result[i -2];
            }
        }
        return result[s.length()];
    }
};

void Test()
{
    Solution solution;
    assert(solution.numDecodings("10") == 1);
    assert(solution.numDecodings("100") == 0);
    assert(solution.numDecodings("17") == 2);
}