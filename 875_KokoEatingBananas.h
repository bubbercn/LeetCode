#pragma once
#include "Common.h"

class Solution
{
public:
    int minEatingSpeed(vector<int> &piles, int h)
    {
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());
        while (left <= right)
        {
            int middle = (left + right) / 2;
            long sum = 0;
            for (auto pile : piles)
            {
                sum += (pile + middle - 1) / middle;
            }
            if (sum <= h)
                right = middle - 1;
            else
                left = middle + 1;
        }
        return max(left, right);
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<int> piles = {3, 6, 7, 11};
    EXPECT_EQ(solution.minEatingSpeed(piles, 8), 4);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> piles = {30, 11, 23, 4, 20};
    EXPECT_EQ(solution.minEatingSpeed(piles, 5), 30);
}

TEST_F(LeetCodeTest, Example3)
{
    vector<int> piles = {30, 11, 23, 4, 20};
    EXPECT_EQ(solution.minEatingSpeed(piles, 6), 23);
}

TEST_F(LeetCodeTest, Failure1)
{
    vector<int> piles = {312884470};
    EXPECT_EQ(solution.minEatingSpeed(piles, 312884469), 2);
}

TEST_F(LeetCodeTest, Failure2)
{
    vector<int> piles = {1, 1, 1, 999999999};
    EXPECT_EQ(solution.minEatingSpeed(piles, 10), 142857143);
}