#pragma once
#include "Common.h"

class Solution
{
public:
    int mergeStones(vector<int> &stones, int k)
    {
        int n = stones.size();
        if ((n - 1) % (k - 1) != 0)
            return -1;

        vector<int> prefixSum(stones.size() + 1);
        for (int i = 0; i < stones.size(); i++)
        {
            prefixSum[i + 1] = prefixSum[i] + stones[i];
        }

        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(k + 1, -1)));
        function<int(int, int, int)> dfs = [&](int begin, int end, int count)
        {
            int &result = dp[begin][end][count];
            if (result != -1)
                return result;

            if (begin == end)
                return 0;

            if (count == 1)
            {
                result = dfs(begin, end, k) + prefixSum[end + 1] - prefixSum[begin];
                return result;
            }

            result = numeric_limits<int>::max();
            for (int i = begin; i < end; i += k - 1)
            {
                result = min(result, dfs(begin, i, 1) + dfs(i + 1, end, count - 1));
            }
            return result;
        };

        return dfs(0, n - 1, 1);
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<int> stones = {3, 2, 4, 1};
    EXPECT_EQ(solution.mergeStones(stones, 2), 20);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> stones = {3, 2, 4, 1};
    EXPECT_EQ(solution.mergeStones(stones, 3), -1);
}

TEST_F(LeetCodeTest, Example3)
{
    vector<int> stones = {3, 5, 1, 2, 6};
    EXPECT_EQ(solution.mergeStones(stones, 3), 25);
}