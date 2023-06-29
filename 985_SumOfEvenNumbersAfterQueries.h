#pragma once
#include "Common.h"

class Solution
{
public:
    vector<int> sumEvenAfterQueries(vector<int> &nums, vector<vector<int>> &queries)
    {
        int n = queries.size();
        vector<int> result(n);
        int sum = 0;
        for (auto i : nums)
        {
            if (i % 2 == 0)
            {
                sum += i;
            }
        }
        for (int i = 0; i < n; i++)
        {
            int val = queries[i][0];
            int index = queries[i][1];
            if (nums[index] % 2 == 0)
            {
                sum -= nums[index];
            }
            nums[index] += val;
            if (nums[index] % 2 == 0)
            {
                sum += nums[index];
            }
            result[i] = sum;
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
    vector<int> nums = {1, 2, 3, 4};
    vector<vector<int>> queries = {{1, 0}, {-3, 1}, {-4, 0}, {2, 3}};
    vector<int> output = {8, 6, 2, 4};
    EXPECT_EQ(solution.sumEvenAfterQueries(nums, queries), output);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> nums = {1};
    vector<vector<int>> queries = {{4, 0}};
    vector<int> output = {0};
    EXPECT_EQ(solution.sumEvenAfterQueries(nums, queries), output);
}