#pragma once
#include "Common.h"

class Solution
{
public:
    vector<int> largestDivisibleSubset(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<int> parent(nums.size(), -1);
        vector<int> depth(nums.size(), 1);
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i - 1; j >= 0; j--)
            {
                if (nums[i] % nums[j] == 0 && depth[j] + 1 > depth[i])
                {
                    parent[i] = j;
                    depth[i] = depth[j] + 1;
                }
            }
        }
        vector<int> result;
        if (auto it = max_element(depth.begin(), depth.end()); it != depth.end())
        {
            int i = it - depth.begin();
            do
            {
                result.emplace_back(nums[i]);
                i = parent[i];
            } while (i != -1);
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<int> input = {1, 2, 3};
    vector<int> output = {1, 2};
    EXPECT_EQ(solution.largestDivisibleSubset(input), output);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> input = {1, 2, 4, 8};
    vector<int> output = {1, 2, 4, 8};
    EXPECT_EQ(solution.largestDivisibleSubset(input), output);
}

TEST_F(LeetCodeTest, Empty)
{
    vector<int> input = {};
    vector<int> output = {};
    EXPECT_EQ(solution.largestDivisibleSubset(input), output);
}