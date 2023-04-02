#pragma once
#include "Common.h"

class Solution
{
public:
    int sumSubarrayMins(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> left(n);
        int i = 0;
        stack<int> temp;
        for (i = n - 1; i >= 0; i--)
        {
            while (!temp.empty() && arr[i] <= arr[temp.top()])
            {
                left[temp.top()] = i;
                temp.pop();
            }
            temp.emplace(i);
        }
        while (!temp.empty())
        {
            left[temp.top()] = i;
            temp.pop();
        }
        vector<int> right(n);
        i = 0;
        temp = stack<int>();
        for (i = 0; i < n; i++)
        {
            while (!temp.empty() && arr[i] < arr[temp.top()])
            {
                right[temp.top()] = i;
                temp.pop();
            }
            temp.emplace(i);
        }
        while (!temp.empty())
        {
            right[temp.top()] = i;
            temp.pop();
        }
        long result = 0;
        for (int i = 0; i < n; i++)
        {
            long temp = static_cast<long>(i - left[i]) * (right[i] - i) * arr[i];
            result = (result + temp) % MOD;
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
    vector<int> arr = {3, 1, 2, 4};
    EXPECT_EQ(solution.sumSubarrayMins(arr), 17);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> arr = {11, 81, 94, 43, 3};
    EXPECT_EQ(solution.sumSubarrayMins(arr), 444);
}

TEST_F(LeetCodeTest, Failure1)
{
    vector<int> arr = {71, 55, 82, 55};
    EXPECT_EQ(solution.sumSubarrayMins(arr), 593);
}