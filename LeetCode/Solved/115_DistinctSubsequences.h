#pragma once
#include "Common.h"

class Solution
{
public:
    int numDistinct(string s, string t)
    {
        int m = static_cast<int>(s.size());
        int n = static_cast<int>(t.size());
        
        if (m == 0 || n == 0)
            return 0;
        
        vector<vector<long long>> result(m, vector<long long>(n, 0));
        
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == 0 && j == 0)
                {
                    result[0][0] = s[0] == t[0] ? 1 : 0;
                }
                else if (i == 0)
                {
                    
                }
                else if (j == 0)
                {
                    result[i][0] = s[i] == t[0] ? result[i - 1][0] + 1 : result[i - 1][0];
                }
                else
                {
                    result[i][j] = s[i] == t[j] ? result[i - 1][j - 1] + result[i - 1][j] : result[i - 1][j];
                }
            }
        }
        
        return static_cast<int>(result[m - 1][n - 1]);
    }
};

void Test()
{
    Solution solution;
    string S, T;
    
    S = "rabbbit";
    T = "rabbit";
    assert(solution.numDistinct(S, T) == 3);
    
    S = "babgbag";
    T = "bag";
    assert(solution.numDistinct(S, T) == 5);
}
