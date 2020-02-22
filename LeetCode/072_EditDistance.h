#pragma once
#include "Common.h"

class Solution {
public:
    int minDistance(string word1, string word2)
    {
        size_t m = 0, n = 0;
        m = word1.size();
        n = word2.size();
        
        vector<vector<size_t>> table(m + 1, vector<size_t>(n + 1, 0));
        for (size_t i = 0; i <= m; i++)
        {
            table[i][0] = i;
        }
        
        for (size_t i = 0; i <= n; i++)
        {
            table[0][i] = i;
        }
        
        for (size_t i = 0; i < m; i++)
        {
            for (size_t j = 0; j < n; j++)
            {
                if (word1[i] == word2[j])
                {
                    table[i + 1][j + 1] = table[i][j];
                }
                else
                {
                    table[i + 1][j + 1] = min(min(table[i][j + 1], table[i + 1][j]), table[i][j]) + 1;
                }
            }
        }
        
        return static_cast<int>(table[m][n]);
    }
};

void Test()
{
    Solution solution;
    assert(solution.minDistance("horse", "ros") == 3);
    assert(solution.minDistance("intention", "execution") == 5);
    assert(solution.minDistance("sea", "ate") == 3);
}
