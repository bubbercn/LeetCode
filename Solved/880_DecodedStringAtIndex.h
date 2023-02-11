#pragma once
#include "Common.h"

class Solution
{
public:
    string decodeAtIndex(string_view s, int k)
    {
        long length = 0;
        stack<string> ops;
        string temp;
        for (auto c : s)
        {
            if (c >= '2' and c <= '9')
            {
                int repeat = c - '0';
                length *= repeat;

                ops.emplace(temp);
                temp.clear();
                ops.emplace(string(1, c));
                if (length >= k)
                {
                    return helper(ops, k, length);
                }
            }
            else
            {
                temp += c;
                length++;
                if (length == k)
                    return string(1, c);
            }
        }
        return {};
    }

private:
    string helper(stack<string> &ops, int k, long length)
    {
        while (!ops.empty())
        {
            string &top = ops.top();
            if (top[0] >= '2' && top[0] <= '9')
            {
                int repeat = top[0] - '0';
                length /= repeat;
                k %= length;
                if (k == 0)
                    k += length;
            }
            else
            {
                int offset = k - length + top.length();
                if (offset > 0)
                    return string(1, top[offset - 1]);
                length -= top.length();
            }
            ops.pop();
        }
        return {};
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    EXPECT_EQ(solution.decodeAtIndex("leet2code3", 10), "o");
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.decodeAtIndex("ha22", 5), "h");
}

TEST_F(LeetCodeTest, Example3)
{
    EXPECT_EQ(solution.decodeAtIndex("a2345678999999999999999", 1), "a");
}

TEST_F(LeetCodeTest, Failure1)
{
    EXPECT_EQ(solution.decodeAtIndex("a23", 6), "a");
}