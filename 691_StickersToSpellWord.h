#pragma once
#include "Common.h"

class Solution
{
public:
    int minStickers(vector<string> &stickers, string_view target)
    {
        int n = stickers.size(), m = target.length();
        int stateSize = 1 << m;
        vector<int> dp(stateSize, -1);
        dp[0] = 0;
        vector<vector<int>> indexLookup(26, vector<int>());
        for (int i = 0; i < m; i++)
        {
            indexLookup[target[i] - 'a'].emplace_back(i);
        }
        for (const auto &sticker : stickers)
        {
            for (int status = 0; status < stateSize; status++)
            {
                if (dp[status] == -1)
                {
                    continue;
                }
                int curStatus = status;
                for (auto c : sticker)
                {
                    for (auto i : indexLookup[c - 'a'])
                    {
                        if ((curStatus & (1 << i)) == 0)
                        {
                            curStatus |= 1 << i;
                            break;
                        }
                    }
                }
                dp[curStatus] = (dp[curStatus] == -1) ? dp[status] + 1 : min(dp[curStatus], dp[status] + 1);
            }
        }
        return dp[(1 << m) - 1];
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<string> stickers = {"with", "example", "science"};
    EXPECT_EQ(solution.minStickers(stickers, "thehat"), 3);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<string> stickers = {"notice", "possible"};
    EXPECT_EQ(solution.minStickers(stickers, "basicbasic"), -1);
}