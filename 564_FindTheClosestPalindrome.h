#pragma once
#include "Common.h"

class Solution
{
public:
    string nearestPalindromic(string n)
    {
        long value = stol(n);
        // 10...0
        if (value < 10 || value == pow(10, n.size() - 1))
        {
            return to_string(value - 1);
        }
        // 10...1
        else if (value - 1 == pow(10, n.size() - 1))
        {
            return to_string(value - 2);
        }
        // 9...9
        else if (value + 1 == pow(10, n.size()))
        {
            return to_string(value + 2);
        }

        for (int i = (n.size() + 1) / 2; i < n.size(); i++)
        {
            n[i] = n[n.size() - i - 1];
        }

        map<int, string> lookup;
        auto push = [&]()
        {
            long temp = stol(n) - value;
            if (temp != 0)
                lookup.emplace(abs(temp), n);
        };

        char *begin, *end;
        if (n.size() & 1)
        {
            begin = &n[n.size() / 2];
            end = begin + 1;
        }
        else
        {
            begin = &n[(n.size() - 1) / 2];
            end = begin + 2;
        }
        string temp = n;
        for (auto i = begin; i != end; i++)
        {
            if (*i != '0')
                (*i)--;
        }
        push();
        n = temp;
        push();
        for (auto i = begin; i != end; i++)
        {
            if (*i != '9')
                (*i)++;
        }
        push();
        return lookup.begin()->second;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    EXPECT_EQ(solution.nearestPalindromic("123"), "121");
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.nearestPalindromic("1"), "0");
}

TEST_F(LeetCodeTest, Failure1)
{
    EXPECT_EQ(solution.nearestPalindromic("10"), "9");
}

TEST_F(LeetCodeTest, Failure2)
{
    EXPECT_EQ(solution.nearestPalindromic("2"), "1");
}

TEST_F(LeetCodeTest, Failure3)
{
    EXPECT_EQ(solution.nearestPalindromic("1283"), "1331");
}

TEST_F(LeetCodeTest, Failure4)
{
    EXPECT_EQ(solution.nearestPalindromic("88"), "77");
}

TEST_F(LeetCodeTest, Failure5)
{
    EXPECT_EQ(solution.nearestPalindromic("1837722381"), "1837667381");
}