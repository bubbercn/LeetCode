#pragma once
#include "Common.h"

class Solution
{
public:
    vector<int> threeEqualParts(vector<int> &arr)
    {
        int n = arr.size();
        int totalCount1 = 0;
        for (auto v : arr)
        {
            if (v == 1)
                totalCount1++;
        }
        if (totalCount1 == 0)
            return {0, 2};

        if (totalCount1 % 3 != 0)
            return {-1, -1};

        int count1 = totalCount1 / 3;
        vector<int> begin(3);
        vector<int> end(3);
        int partition = 0;
        int count = 0;
        int found = false;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == 1)
            {
                if (!found)
                {
                    begin[partition] = i;
                    found = true;
                }
                else
                {
                    found = true;
                }
                count++;
                if (count == count1)
                {
                    end[partition] = i;
                    partition++;
                    found = false;
                    count = 0;
                }
            }
        }
        int endZero = n - 1 - end[2];
        if (begin[2] - end[1] - 1 < endZero)
            return {-1, -1};

        if (begin[1] - end[0] - 1 < endZero)
            return {-1, -1};

        if (cmp(arr, {begin[0], end[0]}, {begin[1], end[1]}) && cmp(arr, {begin[0], end[0]}, {begin[2], end[2]}))
        {
            return {end[0] + endZero, end[1] + endZero + 1};
        }
        return {-1, -1};
    }

private:
    bool cmp(vector<int> &arr, const pair<int, int> &v1, const pair<int, int> &v2)
    {
        if (v1.second - v1.first != v2.second - v2.first)
            return false;

        for (int i1 = v1.first, i2 = v2.first; i1 <= v1.second; i1++, i2++)
        {
            if (arr[i1] != arr[i2])
                return false;
        }
        return true;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<int> arr = {1, 0, 1, 0, 1};
    vector<int> output = {0, 3};
    EXPECT_EQ(solution.threeEqualParts(arr), output);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> arr = {1, 1, 0, 1, 1};
    vector<int> output = {-1, -1};
    EXPECT_EQ(solution.threeEqualParts(arr), output);
}

TEST_F(LeetCodeTest, Example3)
{
    vector<int> arr = {1, 1, 0, 0, 1};
    vector<int> output = {0, 2};
    EXPECT_EQ(solution.threeEqualParts(arr), output);
}
