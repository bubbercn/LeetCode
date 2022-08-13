#pragma once
#include "Common.h"

class Solution
{
public:
    double champagneTower(int poured, int query_row, int query_glass)
    {
        vector<double> glasses(query_row + 1, 0);
        glasses[0] = poured;
        for (int i = 0; i <= query_row; i++)
        {
            vector<double> next(query_row + 1, 0);
            for (int j = 0; j <= i; j++)
            {               
                if (i == query_row)
                {
                    if (j != query_glass)
                        continue;
                    return min(glasses[j], 1.0);
                }   
                else
                {
                    double overflow = (glasses[j] - 1) / 2;
                    if (overflow > 0)
                    {
                        next[j] += overflow;
                        next[j + 1] += overflow;
                    }
                }
            }
            glasses.swap(next);
        }
        return 0;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    EXPECT_EQ(solution.champagneTower(1, 1, 1), 0);
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.champagneTower(2, 1, 1), 0.5);
}

TEST_F(LeetCodeTest, Example3)
{
    EXPECT_EQ(solution.champagneTower(100000009, 33, 17), 1);
}