#pragma once
#include "Common.h"

class Solution
{
public:
    vector<int> addToArrayForm(vector<int> &num, int k)
    {
        vector<int> temp(10001, 0);
        int i = temp.size() - 1;
        while (k != 0)
        {
            temp[i] = k % 10;
            k /= 10;
            i--;
        }
        i = num.size() - 1;
        int j = temp.size() - 1;
        while (i >= 0)
        {
            temp[j] += num[i];
            if (temp[j] >= 10)
            {
                temp[j] -= 10;
                temp[j - 1]++;
            }
            i--;
            j--;
        }
        while (j >= 0)
        {
            if (temp[j] >= 10)
            {
                temp[j] -= 10;
                temp[j - 1]++;
            }
            j--;
        }
        vector<int> result;
        for (auto it = temp.begin(); it != temp.end(); it++)
        {
            if (*it != 0)
            {
                result.assign(it, temp.end());
                break;
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
    vector<int> num = {1, 2, 0, 0};
    int k = 34;
    vector<int> output = {1, 2, 3, 4};
    EXPECT_EQ(solution.addToArrayForm(num, k), output);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> num = {2, 7, 4};
    int k = 181;
    vector<int> output = {4, 5, 5};
    EXPECT_EQ(solution.addToArrayForm(num, k), output);
}

TEST_F(LeetCodeTest, Example3)
{
    vector<int> num = {2, 1, 5};
    int k = 806;
    vector<int> output = {1, 0, 2, 1};
    EXPECT_EQ(solution.addToArrayForm(num, k), output);
}