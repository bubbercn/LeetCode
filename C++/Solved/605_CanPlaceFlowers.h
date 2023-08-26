#pragma once
#include "Common.h"

class Solution
{
public:
    bool canPlaceFlowers(vector<int> &flowerbed, int n)
    {
        for (int i = 0; i < flowerbed.size();)
        {
            if (flowerbed[i] == 0)
            {
                if (i == flowerbed.size() - 1 || flowerbed[i + 1] == 0)
                {
                    n--;
                    i += 2;
                }
                else
                {
                    i += 3;
                }
            }
            else
            {
                i += 2;
            }
        }
        return n <= 0;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<int> flowerbed = {1, 0, 0, 0, 1};
    EXPECT_EQ(solution.canPlaceFlowers(flowerbed, 1), true);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> flowerbed = {1, 0, 0, 0, 1};
    EXPECT_EQ(solution.canPlaceFlowers(flowerbed, 2), false);
}