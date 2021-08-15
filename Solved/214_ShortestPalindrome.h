#pragma once
#include "Common.h"

class Solution
{
public:
    string shortestPalindrome(string s)
    {
        string r = s;
        reverse(r.begin(), r.end());
        string combination = s + "&" + r;
        vector<int> dp(combination.length(), 0);
        for (int i = 0; i < dp.size(); i++)
        {
            if (i == 0)
            {
                dp[i] = 0;
            }
            else
            {
                int cur = dp[i - 1] ;
                while (cur != 0 && combination[i] != combination[cur])
                {
                    cur = dp[cur - 1];
                }
                if (combination[i] == combination[cur])
                {
                    dp[i] = cur + 1;
                }
                else
                {
                    dp[i] = 0;
                }
            }
        }
        return r.substr(0, r.length() - *dp.rbegin())  + s;
    }
};

void Test()
{
    Solution solution;

    assert(solution.shortestPalindrome("aacecaaa") == "aaacecaaa");
    assert(solution.shortestPalindrome("abcd") == "dcbabcd");
}