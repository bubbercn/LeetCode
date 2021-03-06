#pragma once
#include "Common.h"

class Solution
{
public:
    int countSegments(const string &s)
    {
        int result = 0;
        int isStarted = false;
        for (auto c : s)
        {
            if (c != ' ')
            {
                isStarted = true;
            }
            else if (isStarted)
            {
                isStarted = false;
                result++;
            }
        }
        if (isStarted)
            result++;
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
    EXPECT_EQ(solution.countSegments("Hello, my name is John"), 5);
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.countSegments("Hello"), 1);
}

TEST_F(LeetCodeTest, Example3)
{
    EXPECT_EQ(solution.countSegments("love live! mu'sic forever"), 4);
}

TEST_F(LeetCodeTest, Example4)
{
    EXPECT_EQ(solution.countSegments(""), 0);
}