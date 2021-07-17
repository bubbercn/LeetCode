#pragma once
#include "Common.h"

class Solution
{
public:
    int magicalString(int n)
    {
        if (n == 1)
            return 1;
        if (n == 2)
            return 1;

        list<short> q{1, 2, 2};
        int result{1};
        auto curPos = q.begin();
        curPos++;
        curPos++;
        while (q.size() < n)
        {
            short toAppend = *q.rbegin() == 1 ? 2 : 1;
            for (int i = 0; i < *curPos; i++)
            {
                q.emplace_back(toAppend);
                if (toAppend == 1)
                    result++;
            }
            curPos++;
        }
        if (q.size() > n && *q.rbegin() == 1)
            result--;
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
    EXPECT_EQ(solution.magicalString(6), 3);
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.magicalString(1), 1);
}

TEST_F(LeetCodeTest, Case1)
{
    EXPECT_EQ(solution.magicalString(4), 2);
}