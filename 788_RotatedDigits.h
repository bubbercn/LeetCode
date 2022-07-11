#pragma once
#include "Common.h"

class Solution
{
public:
    int rotatedDigits(int n)
    {
        int result = 0;
        for (int i = 1; i <= n; i++)
        {
            if (isGood(i))
                result++;
        }
        return result;
    }

private:
    bool isGood(int n)
    {
        string s = to_string(n);
        bool isGood = false;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '0' || s[i] == '1' || s[i] == '8')
                continue;
            if (s[i] == '2' || s[i] == '5' || s[i] == '6' || s[i] == '9')
            {
                isGood = true;
            }
            else
            {
                return false;
            }
        }
        return isGood;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    EXPECT_EQ(solution.rotatedDigits(10), 4);
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.rotatedDigits(1), 0);
}

TEST_F(LeetCodeTest, Example3)
{
    EXPECT_EQ(solution.rotatedDigits(2), 1);
}