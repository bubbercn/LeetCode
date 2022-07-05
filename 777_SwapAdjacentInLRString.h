#pragma once
#include "Common.h"

class Solution
{
public:
    bool canTransform(string_view start, string_view end)
    {
        int n = start.size();
        int xIndex1 = -1, xIndex2 = -1;
        for (int i = 0; i < n; ++i)
        {
            if (start[i] == end[i])
                continue;

            if (start[i] == 'X')
            {
                if (xIndex1 == -1)
                {
                    xIndex1 = i;
                }
                else
                {
                    return false;
                }
            }
            if (end[i] == 'X')
            {
                if (xIndex2 == -1)
                {
                    xIndex2 = i;
                }
                else
                {
                    return false;
                }
            }
            if (xIndex1 != -1 && xIndex2 != -1)
            {
                if (xIndex1 < xIndex2)
                {
                    if (start.substr(xIndex1 + 1, xIndex2 - xIndex1) != end.substr(xIndex1, xIndex2 - xIndex1))
                        return false;
                    
                }
                else
                {

                }
                xIndex1 = -1;
                xIndex2 = -1;
            }
            else if (xIndex1 != -1 || xIndex2 != -1)
            {
                return false;
            }
        }
        if (xIndex1 == -1 && xIndex2 == -1)
        {
            return true;
        }
        return false;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    EXPECT_EQ(solution.canTransform("RXXLRXRXL", "XRLXXRRLX"), true);
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.canTransform("X", "L"), false);
}