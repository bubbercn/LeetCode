#pragma once
#include "Common.h"

class Solution
{
public:
    vector<int> powerfulIntegers(int x, int y, int bound)
    {
        unordered_set<int> result;
        int tx = 1;
        while (tx < bound)
        {
            int ty = 1;
            while (tx + ty <= bound)
            {
                result.emplace(tx + ty);
                if (y == 1)
                    break;
                ty *= y;
            }
            if (x == 1)
                break;
            tx *= x;
        }
        return {result.begin(), result.end()};
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<int> output = {2, 3, 4, 5, 7, 9, 10};
    auto temp = solution.powerfulIntegers(2, 3, 10);
    sort(temp.begin(), temp.end());
    EXPECT_EQ(temp, output);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> output = {2, 4, 6, 8, 10, 14};
    auto temp = solution.powerfulIntegers(3, 5, 15);
    sort(temp.begin(), temp.end());
    EXPECT_EQ(temp, output);
}