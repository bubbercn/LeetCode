#pragma once
#include "Common.h"

class Solution
{
public:
    int lenLongestFibSubseq(vector<int> &arr)
    {
        int result = 0;
        int n = arr.size();
        unordered_map<int, int> lookup;
        for (int i = 0; i < n; i++)
        {
            lookup.emplace(arr[i], i);
        }
        vector<vector<bool>> visited(n, vector<bool>(n));
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (visited[i][j])
                    continue;
                
                int length = 2;
                int x1 = i;
                int x2 = j;
                visited[x1][x2] = true;
                int temp = arr[x1] + arr[x2];
                auto it = lookup.find(temp);
                while (it != lookup.end())
                {
                    length++;
                    x1 = x2;
                    x2 = it->second;
                    visited[x1][x2] = true;
                    temp = arr[x1] + arr[x2];
                    it = lookup.find(temp);
                }
                length = length > 2 ? length : 0;
                result = max(result, length);
            }
        }
        return result;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8};
    EXPECT_EQ(solution.lenLongestFibSubseq(arr), 5);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> arr = {1, 3, 7, 11, 12, 14, 18};
    EXPECT_EQ(solution.lenLongestFibSubseq(arr), 3);
}