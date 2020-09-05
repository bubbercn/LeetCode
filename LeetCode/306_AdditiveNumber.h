#pragma once
#include "Common.h"

class Solution
{
public:
    bool isAdditiveNumber(const string &num)
    {
        list<long> states;
        return dfs(num, 0, 1, states);
    }

private:
    bool dfs(const string &num, size_t pos, size_t length, list<long> &states)
    {
        if (states.size() < 3)
        {
            for (size_t i = length; pos + i <= num.length(); i++)
            {
                if (states.size() < 2 && i > (num.length() - pos) / 2)
                    break;

                long value = getValue(num, pos, i);
                if (value != -1)
                {
                    states.emplace_back(value);
                    if (dfs(num, pos + i, 1, states))
                    {
                        return true;
                    }
                    else
                    {
                        int temp = states.back();
                        states.pop_back();
                        if (temp == -1)
                            break;
                    }
                }
            }
            return false;
        }
        else
        {
            long num1 = states.front();
            long num2 = *(++states.begin());
            long num3 = states.back();
            if (num1 + num2 == num3)
            {
                if (pos == num.length())
                {
                    return true;
                }
                else
                {
                    states.pop_front();
                    bool temp = dfs(num, pos, 1, states);
                    states.emplace_front(num1);
                    return temp;
                }
            }
            else
            {
                if (num1 + num2 < num3)
                {
                    states.back() = -1;
                }
                return false;
            }
        }
    }

    long getValue(const string &num, size_t pos, size_t length)
    {
        if (num[pos] == '0' && length != 1)
            return -1;

        long sum = 0;

        while (length-- > 0)
        {
            sum = sum * 10 + (num[pos++] - '0');
        }

        return sum;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    EXPECT_EQ(solution.isAdditiveNumber("112358"), true);
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.isAdditiveNumber("199100199"), true);
}

TEST_F(LeetCodeTest, Example3)
{
    EXPECT_EQ(solution.isAdditiveNumber("1203"), false);
}

TEST_F(LeetCodeTest, Example4)
{
    EXPECT_EQ(solution.isAdditiveNumber("1023"), false);
}

TEST_F(LeetCodeTest, Empty)
{
    EXPECT_EQ(solution.isAdditiveNumber(""), false);
}

TEST_F(LeetCodeTest, SingleDigit)
{
    EXPECT_EQ(solution.isAdditiveNumber("1"), false);
}

TEST_F(LeetCodeTest, DoubleDigit)
{
    EXPECT_EQ(solution.isAdditiveNumber("11"), false);
}

TEST_F(LeetCodeTest, SimpleTrue)
{
    EXPECT_EQ(solution.isAdditiveNumber("112"), true);
}

TEST_F(LeetCodeTest, SimpleFalse)
{
    EXPECT_EQ(solution.isAdditiveNumber("111"), false);
}

TEST_F(LeetCodeTest, Failure1)
{
    EXPECT_EQ(solution.isAdditiveNumber("12122436"), true);
}

TEST_F(LeetCodeTest, Failure2)
{
    EXPECT_EQ(solution.isAdditiveNumber("11235813213455890144"), false);
}

TEST_F(LeetCodeTest, Failure3)
{
    EXPECT_EQ(solution.isAdditiveNumber("11111111111011111111111"), true);
}