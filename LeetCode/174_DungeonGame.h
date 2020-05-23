#pragma once
#include "Common.h"

class Solution
{
public:
    int calculateMinimumHP(vector<vector<int>> &dungeon)
    {
        if (dungeon.empty() || dungeon[0].empty())
            return 1;

        int m = dungeon.size();
        int n = dungeon[0].size();

        vector<int> dp(n);

        int max = INT_MIN;

        for (int i = m - 1; i >= 0; i--)
        {
            for (int j = n - 1; j >= 0; j--)
            {
                if (i == m -1 && j == n - 1)
                {
                    dp[j] = 1 - dungeon[i][j];
                }
                else if (i == m - 1)
                {
                    dp[j] = dp[j + 1] - dungeon[i][j];
                }
                else if (j == n - 1)
                {
                    dp[j] = dp[j] - dungeon[i][j];
                }
                else
                {
                    dp[j] = min(dp[j], dp[j + 1]) - dungeon[i][j];
                }
                if (dp[j] < 1) {
                    dp[j] = 1;
                }
            }
         }

        return dp[0];
    }
};

void Test()
{
    Solution solution;
    vector<vector<int>> dungeon;

    dungeon = {
        {-2, -3, 3},
        {-5, -10, 1},
        {10, 30, -5}
    };
    assert(solution.calculateMinimumHP(dungeon) == 7);

    dungeon = {
        {1, -3, 3},
        {0, -2, 0},
        {-3, -3, -3}
    };
    assert(solution.calculateMinimumHP(dungeon) == 3);

    dungeon = {
        {1, -4, 5, -99},
        {2, -2, -2, -1}
    };
    assert(solution.calculateMinimumHP(dungeon) == 3);
}