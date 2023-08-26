#pragma once
#include "Common.h"

class Solution
{
public:
    bool judgeCircle(string_view moves)
    {
        int x = 0, y = 0;
        for (auto move : moves)
        {
            switch (move)
            {
            case 'U':
                x--;
                break;
            case 'D':
                x++;
                break;
            case 'L':
                y--;
                break;
            case 'R':
                y++;
                break;
            default:
                break;
            }
        }
        return x == 0 && y == 0;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    EXPECT_EQ(solution.judgeCircle("UD"), true);
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.judgeCircle("LL"), false);
}

TEST_F(LeetCodeTest, Example3)
{
    EXPECT_EQ(solution.judgeCircle("RRDD"), false);
}

TEST_F(LeetCodeTest, Example4)
{
    EXPECT_EQ(solution.judgeCircle("LDRRLRUULR"), false);
}