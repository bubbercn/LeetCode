#pragma once
#include "Common.h"

class Solution
{
public:
    vector<int> fairCandySwap(vector<int> &aliceSizes, vector<int> &bobSizes)
    {
        int sumA = accumulate(aliceSizes.begin(), aliceSizes.end(), 0);
        int sumB = accumulate(bobSizes.begin(), bobSizes.end(), 0);
        int target = (sumA + sumB) / 2;
        unordered_set<int> lookup(bobSizes.begin(), bobSizes.end());
        for (auto n : aliceSizes)
        {
            int temp = target - sumA + n;
            if (lookup.count(temp) != 0)
                return {n, temp};
        }
        return {};
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<int> aliceSizes = {1, 1};
    vector<int> bobSizes = {2, 2};
    vector<int> output = {1, 2};
    EXPECT_EQ(solution.fairCandySwap(aliceSizes, bobSizes), output);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> aliceSizes = {1, 2};
    vector<int> bobSizes = {2, 3};
    vector<int> output = {1, 2};
    EXPECT_EQ(solution.fairCandySwap(aliceSizes, bobSizes), output);
}

TEST_F(LeetCodeTest, Example3)
{
    vector<int> aliceSizes = {2};
    vector<int> bobSizes = {1, 3};
    vector<int> output = {2, 3};
    EXPECT_EQ(solution.fairCandySwap(aliceSizes, bobSizes), output);
}