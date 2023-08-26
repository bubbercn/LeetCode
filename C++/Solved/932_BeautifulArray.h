#pragma once
#include "Common.h"

class Solution
{
public:
    vector<int> beautifulArray(int n)
    {
        if (n == 1)
            return {1};

        if (auto it = lookup.find(n); it != lookup.end())
            return it->second;
        vector<int> result(n);
        int oddCount = (n + 1) / 2;
        for (int i = 0; i < oddCount; i++)
        {
            result[i] = 2 * i + 1;
        }
        int evenCount = n - oddCount;
        for (int i = 0; i < evenCount; i++)
        {
            result[oddCount + i] = 2 * (i + 1);
        }
        helper(result, 0, oddCount);
        helper(result, oddCount, n);
        lookup.emplace(n, result);
        return result;
    }
    void helper(vector<int> &nums, int begin, int end)
    {
        int n = end - begin;
        auto index = beautifulArray(n);
        vector<int> temp(nums.begin() + begin, nums.begin() + end);
        for (int i = 0; i < n; i++)
        {
            *(nums.begin() + begin + i) = temp[index[i] - 1];
        }
    }

private:
    unordered_map<int, vector<int>> lookup;
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<int> output = {1, 3, 2, 4};
    EXPECT_EQ(solution.beautifulArray(4), output);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> output = {1, 5, 3, 2, 4};
    EXPECT_EQ(solution.beautifulArray(5), output);
}
