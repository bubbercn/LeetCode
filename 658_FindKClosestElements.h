#pragma once
#include "Common.h"

class Solution
{
public:
    vector<int> findClosestElements(vector<int> &arr, int k, int x)
    {
        vector<int> result;
        int count = 0;
        auto middle = lower_bound(arr.begin(), arr.end(), x);
        auto left = (middle == arr.begin()) ? arr.end() : middle - 1;
        auto right = middle;
        int leftDistance = (left == arr.end()) ? numeric_limits<int>::max() : abs(*left - x);
        int rightDistance = (right == arr.end()) ? numeric_limits<int>::max() : abs(*right - x);
        while (count < k)
        {
            bool leftWin = false;
            if (leftDistance == rightDistance)
            {
                if (*left < *right)
                {
                    leftWin = true;
                }
            }
            else if (leftDistance < rightDistance)
            {
                leftWin = true;
            }
            if (leftWin)
            {
                result.emplace_back(*left);
                left = (left == arr.begin()) ? arr.end() : left - 1;
                leftDistance = (left == arr.end()) ? numeric_limits<int>::max() : abs(*left - x);
            }
            else
            {
                result.emplace_back(*right);
                right = (right == arr.end()) ? arr.end() : right + 1;
                rightDistance = (right == arr.end()) ? numeric_limits<int>::max() : abs(*right - x);
            }
            count++;
        }
        sort(result.begin(), result.end());
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
    vector<int> arr = {1, 2, 3, 4, 5};
    vector<int> output = {1, 2, 3, 4};
    EXPECT_EQ(solution.findClosestElements(arr, 4, 3), output);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> arr = {1, 2, 3, 4, 5};
    vector<int> output = {1, 2, 3, 4};
    EXPECT_EQ(solution.findClosestElements(arr, 4, -1), output);
}

TEST_F(LeetCodeTest, Failure1)
{
    vector<int> arr = {0, 0, 1, 2, 3, 3, 4, 7, 7, 8};
    vector<int> output = {3, 3, 4};
    EXPECT_EQ(solution.findClosestElements(arr, 3, 5), output);
}