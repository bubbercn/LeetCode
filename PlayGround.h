#pragma once
#include "Common.h"

class SStack
{
public:
    void push(int value)
    {
        if (!data.empty() && value > data.top())
            clear();
        data.push(value);
    }

    void clear()
    {
        stack<int> temp;
        data.swap(temp);
    }

    size_t size() const
    {
        return data.size();
    }

private:
    stack<int> data;
};

class Solution
{
public:
    vector<int> goodIndices(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<bool> lookup(n, false);
        SStack window;
        for (int i = n - 1; i >= n - k; i--)
        {
            window.push(nums[i]);
        }
        for (int i = n - k - 1; i >= 0; i--)
        {
            lookup[i] = window.size() >= k;
            window.push(nums[i]);
        }
        vector<int> result;
        window.clear();
        for (int i = 0; i < k; i++)
        {
            window.push(nums[i]);
        }
        for (int i = k; i < n - k; i++)
        {
            if (lookup[i] && window.size() >= k)
            {
                result.emplace_back(i);
            }
            window.push(nums[i]);
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
    vector<int> nums = {2, 1, 1, 1, 3, 4, 1};
    vector<int> output = {2, 3};
    EXPECT_EQ(solution.goodIndices(nums, 2), output);
}
