#pragma once
#include "Common.h"

class Solution
{
public:
    string pushDominoes(string_view dominoes)
    {
        int n = dominoes.length();
        string result(dominoes);
        size_t begin = -1;
        size_t end = -1;
        bool dot = false;
        for (int i = 0; i < n; i++)
        {
            if (result[i] == 'R')
            {
                if (begin != -1 && dot)
                {
                    for (int j = begin + 1; j < i; j++)
                    {
                        if (result[j] == '.')
                        {
                            result[j] = 'R';
                        }
                    }
                    dot = false;
                }
                begin = i;
            }
            else if (result[i] == 'L')
            {
                if (begin == -1)
                {
                    if (dot)
                    {
                        for (int j = end + 1; j < i; j++)
                        {
                            if (result[j] == '.')
                            {
                                result[j] = 'L';
                            }
                        }
                        dot = false;
                    }
                }
                else
                {
                    if (dot)
                    {
                        for (int j = begin + 1, k = i - 1; j < k; j++, k--)
                        {
                            result[j] = 'R';
                            result[k] = 'L';
                        }
                    }
                    begin = -1;
                }
                end = i;
            }
            else
            {
                dot = true;
            }
        }
        if (begin != -1 && dot)
        {
            for (int i = begin + 1; i < n; i++)
            {
                if (result[i] == '.')
                {
                    result[i] = 'R';
                }
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
    EXPECT_EQ(solution.pushDominoes("RR.L"), "RR.L");
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.pushDominoes(".L.R...LR..L.."), "LL.RR.LLRRLL..");
}
