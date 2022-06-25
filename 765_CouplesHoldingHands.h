#pragma once
#include "Common.h"

class Solution
{
public:
    int minSwapsCouples(vector<int> &row)
    {
        int n = row.size();
        unordered_map<int, int> person2IndexMap;
        for (int i = 0; i < n; i++)
        {
            person2IndexMap.emplace(row[i], i);
        }
        int result = 0;
        for (int i = 0; i < n; i += 2)
        {
            if (row[i] > row[i + 1])
            {
                swap(row[i], row[i + 1]);
                swap(person2IndexMap[row[i]], person2IndexMap[row[i + 1]]);
            }
            if (row[i] % 2 == 0 && row[i] + 1 == row[i + 1])
                continue;

            int sourceIndex = i + 1;
            int targetIndex = row[i] % 2 == 0 ? person2IndexMap[row[i] + 1] : person2IndexMap[row[i] - 1];
            swap(row[sourceIndex], row[targetIndex]);
            swap(person2IndexMap[row[sourceIndex]], person2IndexMap[row[targetIndex]]);
            result++;
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
    vector<int> row = {0, 2, 1, 3};
    EXPECT_EQ(solution.minSwapsCouples(row), 1);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> row = {3, 2, 0, 1};
    EXPECT_EQ(solution.minSwapsCouples(row), 0);
}

TEST_F(LeetCodeTest, Failure1)
{
    vector<int> row = {5, 3, 4, 2, 1, 0};
    EXPECT_EQ(solution.minSwapsCouples(row), 1);
}

TEST_F(LeetCodeTest, Failure2)
{
    vector<int> row = {6, 2, 1, 7, 4, 5, 3, 8, 0, 9};
    EXPECT_EQ(solution.minSwapsCouples(row), 3);
}