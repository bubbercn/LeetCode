#pragma once
#include "Common.h"

class Solution 
{
public:
    int minCut(string s) 
    {
        int len = s.length();
        if (len <= 1) 
        {
            return 0;
        }

        vector<int> dp(len, INT_MAX);

        for (int i = 0; i < len; i++) 
        {
            if (isPalindrome(s, 0, i + 1)) 
            {
                dp[i] = 0;
                continue;
            }

            for (int j = 0; j <= i; j++) 
            {
                if (isPalindrome(s, j + 1, i + 1))
                {
                    dp[i] = min(dp[i], dp[j] + 1);
                }
            }
        }
        return dp[len - 1];

    }
private:
    bool isPalindrome(const string &s, size_t begin, size_t end)
    {
        while (begin < end)
        {
            if (s[begin] != s[end - 1])
                return false;

            begin++;
            end--;
        }
        return true;
    }
};

void Test()
{
    Solution solution;
    assert(solution.minCut("aab") == 1);
}