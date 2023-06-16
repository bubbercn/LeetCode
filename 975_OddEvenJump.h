#pragma once
#include "Common.h"

class Solution
{
public:
    int oddEvenJumps(vector<int> &arr)
    {
        int result = 0;
        odd.clear();
        even.clear();
        oddNext.clear();
        evenNext.clear();

        int n = arr.size();
        {
            set<pair<int, int>> temp;
            for (int i = n - 1; i >= 0; i--)
            {
                auto it = temp.lower_bound({arr[i], i});
                if (it != temp.end())
                {
                    oddNext[i] = it->second;
                }
                temp.insert({arr[i], i});
            }
        }
        {
            set<pair<int, int>> temp;
            for (int i = n - 1; i >= 0; i--)
            {
                auto it = temp.lower_bound({-arr[i], i});
                if (it != temp.end())
                {
                    evenNext[i] = it->second;
                }
                temp.insert({-arr[i], i});
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (canJump(arr, i, true))
            {
                result++;
            }
        }
        return result;
    }

private:
    bool canJump(const vector<int> &arr, int index, bool isOdd)
    {
        if (index == arr.size() - 1)
        {
            return true;
        }

        if (isOdd)
        {
            if (odd.find(index) != odd.end())
            {
                return odd[index];
            }
        }
        else
        {
            if (even.find(index) != even.end())
            {
                return even[index];
            }
        }

        int nextIndex = -1;
        if (isOdd)
        {
            if (oddNext.find(index) != oddNext.end())
            {
                nextIndex = oddNext[index];
            }
        }
        else
        {
            if (evenNext.find(index) != evenNext.end())
            {
                nextIndex = evenNext[index];
            }
        }

        bool result = false;
        if (nextIndex != -1)
        {
            result = canJump(arr, nextIndex, !isOdd);
        }
        if (isOdd)
        {
            odd[index] = result;
        }
        else
        {
            even[index] = result;
        }
        return result;
    }
    unordered_map<int, bool> odd;
    unordered_map<int, bool> even;
    unordered_map<int, int> oddNext;
    unordered_map<int, int> evenNext;
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<int> arr = {10, 13, 12, 14, 15};
    EXPECT_EQ(solution.oddEvenJumps(arr), 2);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> arr = {2, 3, 1, 1, 4};
    EXPECT_EQ(solution.oddEvenJumps(arr), 3);
}

TEST_F(LeetCodeTest, Example3)
{
    vector<int> arr = {5, 1, 3, 4, 2};
    EXPECT_EQ(solution.oddEvenJumps(arr), 3);
}