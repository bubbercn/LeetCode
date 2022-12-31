#pragma once
#include "Common.h"

class Solution
{
public:
    int peakIndexInMountainArray(vector<int> &arr)
    {
        return binarySearch(arr, 0, arr.size());
    }

private:
    int binarySearch(const vector<int> &arr, int begin, int end)
    {
        if (begin >= end)
            return -1;

        int middle = (begin + end) / 2;

        if (arr[middle] > arr[middle - 1] && arr[middle] > arr[middle + 1])
            return middle;

        if (arr[middle] > arr[middle - 1])
            return binarySearch(arr, middle + 1, end);

        return binarySearch(arr, begin, middle);
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<int> arr = {0, 1, 0};
    EXPECT_EQ(solution.peakIndexInMountainArray(arr), 1);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> arr = {0, 2, 1, 0};
    EXPECT_EQ(solution.peakIndexInMountainArray(arr), 1);
}

TEST_F(LeetCodeTest, Example3)
{
    vector<int> arr = {0, 10, 5, 2};
    EXPECT_EQ(solution.peakIndexInMountainArray(arr), 1);
}