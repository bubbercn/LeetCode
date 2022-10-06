#pragma once
#include "Common.h"

class Solution
{
public:
    int numFactoredBinaryTrees(vector<int> &arr)
    {
        unordered_set<int> lookup(arr.begin(), arr.end());
        sort(arr.begin(), arr.end());
        unordered_map<int, long> dp;
        for (auto num : arr)
        {
            dp.emplace(num, 1);
        }
        int result = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            long temp = dp[arr[i]];
            for (int j = 0; j < i; j++)
            {
                if (arr[i] % arr[j] == 0 && lookup.count(arr[i] / arr[j]) != 0)
                {
                    temp += dp[arr[j]] * dp[arr[i] / arr[j]];
                    temp %= MOD;
                }
            }
            dp[arr[i]] = temp;
            result += temp;
            result %= MOD;
        }
        return result;
    }

private:
    static constexpr int MOD = 1000000000 + 7;
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<int> arr = {2, 4};
    EXPECT_EQ(solution.numFactoredBinaryTrees(arr), 3);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> arr = {2, 4, 5, 10};
    EXPECT_EQ(solution.numFactoredBinaryTrees(arr), 7);
}

TEST_F(LeetCodeTest, Failure1)
{
    vector<int> arr = {18, 3, 6, 2};
    EXPECT_EQ(solution.numFactoredBinaryTrees(arr), 12);
}