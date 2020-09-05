#pragma once
#include "Common.h"

struct state
{
    long value;
    size_t pos;
    size_t length;
};

class Solution
{
public:
    bool isAdditiveNumber(const string &num)
    {
        list<state> states;
        return dfs(num, 0，1，states);
    }

private:
    bool dfs(const string &num, size_t pos, size_t length, list<state> &states)
    {
        do
        {
            if (moveAndValidate(const string &num, size_t pos, size_t length, list<state> &states))
            {
                if (dfs())
                    return true;
            }

        } while (restore()) return false;
    }

    int moveAndValidate(const string &num, size_t pos, size_t length, list<state> &states)
    {
        if (states.size() <)
    }

    long getValue(const string &num, size_t pos, size_t length)
    {
        if (num[pos] == 0)
            return -1;

        long sum = 0;

        while (length-- > 0)
        {
            sum = sum * 10 + num[pos++];
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