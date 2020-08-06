#pragma once
#include "Common.h"

class Solution
{
public:
    int numSquares(int n)
    {
        vector<int> dp(n + 1);
        for (int i = 0; i <= n; i++)
        {
            if (i == 0)
                dp[0] = 0;

            int min = INT_MAX;
            int radix = 1;
            while (true)
            {
                int temp = i - radix * radix;
                if (temp < 0)
                    break;
                min = ::min(min, dp[temp]);
                radix++;
                dp[i] = min + 1;
            }
        }
        return dp[n];
    }
};

void Test()
{
    Solution solution;
    assert(solution.numSquares(12) == 3);
}