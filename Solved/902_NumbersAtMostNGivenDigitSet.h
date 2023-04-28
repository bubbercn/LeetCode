#pragma once
#include "Common.h"

class Solution
{
public:
    int atMostNGivenDigitSet(vector<string> &digits, int n)
    {
        string nString = to_string(n);
        int len = nString.length();
        int result = 0;
        result += helper1(len - 1, digits.size());
        result += helper2(digits, nString);
        return result;
    }

private:
    int helper1(int digitCount, int n)
    {
        int result = 0;
        int temp = 1;
        while (digitCount-- > 0)
        {
            temp *= n;
            result += temp;
        }
        return result;
    }
    int helper2(vector<string> &digits, string_view s)
    {
        if (s.empty())
            return 1;

        int result = 0;
        int m = 0;
        for (auto digit : digits)
        {
            if (digit[0] < s[0])
            {
                m++;
            }
            else if (digit[0] == s[0])
            {
                result += helper2(digits, s.substr(1));
            }
        }
        result += pow(digits.size(), s.length() - 1) * m;
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
    vector<string> digits = {"1", "3", "5", "7"};
    EXPECT_EQ(solution.atMostNGivenDigitSet(digits, 100), 20);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<string> digits = {"1", "4", "9"};
    EXPECT_EQ(solution.atMostNGivenDigitSet(digits, 1000000000), 29523);
}

TEST_F(LeetCodeTest, Example3)
{
    vector<string> digits = {"7"};
    EXPECT_EQ(solution.atMostNGivenDigitSet(digits, 8), 1);
}

TEST_F(LeetCodeTest, Failure1)
{
    vector<string> digits = {"3", "4", "8"};
    EXPECT_EQ(solution.atMostNGivenDigitSet(digits, 4), 2);
}

TEST_F(LeetCodeTest, Failure2)
{
    vector<string> digits = {"5", "6"};
    EXPECT_EQ(solution.atMostNGivenDigitSet(digits, 19), 2);
}

TEST_F(LeetCodeTest, Failure3)
{
    vector<string> digits = {"1"};
    EXPECT_EQ(solution.atMostNGivenDigitSet(digits, 834), 3);
}

TEST_F(LeetCodeTest, Failure4)
{
    vector<string> digits = {"1", "2", "3", "6", "7", "8"};
    EXPECT_EQ(solution.atMostNGivenDigitSet(digits, 211), 79);
}