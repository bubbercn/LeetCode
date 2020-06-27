#pragma once
#include "Common.h"

class Solution
{
public:
    int maximalSquare(vector<vector<char>> &matrix)
    {
        if (matrix.empty())
            return 0;
            
        vector<vector<vector<int>>> dp(matrix.size(), vector<vector<int>>(matrix[0].size(), vector<int>(3, 0)));
        int max = 0;
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[0].size(); j++)
            {
                if (i == 0 && j == 0)
                {
                    dp[i][j][0] = matrix[i][j] - '0';
                    dp[i][j][1] = matrix[i][j] - '0';
                    dp[i][j][2] = matrix[i][j] - '0';
                }
                else if (i == 0)
                {
                    dp[i][j][0] = matrix[i][j] == '0' ? 0 : dp[i][j - 1][0] + 1;
                    dp[i][j][1] = matrix[i][j] - '0';
                    dp[i][j][2] = matrix[i][j] - '0';
                }
                else if (j == 0)
                {
                    dp[i][j][0] = matrix[i][j] - '0';
                    dp[i][j][1] = matrix[i][j] == '0' ? 0 : dp[i - 1][j][1] + 1;
                    dp[i][j][2] = matrix[i][j] - '0';
                }
                else
                {
                    dp[i][j][0] = matrix[i][j] == '0' ? 0 : dp[i][j - 1][0] + 1;
                    dp[i][j][1] = matrix[i][j] == '0' ? 0 : dp[i - 1][j][1] + 1;
                    dp[i][j][2] = matrix[i][j] == '0' ? 0 : min(dp[i - 1][j - 1][2] + 1, min(dp[i][j][0], dp[i][j][1]));
                }
                max = ::max(max, dp[i][j][2]);
            }
        }
        return max * max;
    }
};

void Test()
{
    Solution solution;
    vector<vector<char>> matrix = {{'1', '0', '1', '0', '0'}, {'1', '0', '1', '1', '1'}, {'1', '1', '1', '1', '1'}, {'1', '0', '0', '1', '0'}};
    solution.maximalSquare(matrix);
}
