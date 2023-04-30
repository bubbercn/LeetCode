#pragma once
#include "Common.h"

class Solution
{
public:
    bool isLongPressedName(string_view name, string_view typed)
    {
        if (name.length() > typed.length())
            return false;
        int n = 0;
        int t = 0;
        while (true)
        {
            auto [v1, c1] = getNext(name, n);
            auto [v2, c2] = getNext(typed, t);
            if (v1 != v2)
                return false;
            if (c1 > c2)
                return false;
            if (v1 == 0 && v2 == 0)
                break;
            n += c1;
            t += c2;
        }
        return true;
    }

private:
    pair<char, int> getNext(string_view s, int begin)
    {
        if (begin > s.length())
            return {0, 0};

        char v = s[begin++];
        int c = 1;
        while (begin < s.length() && s[begin] == v)
        {
            c++;
            begin++;
        }
        return {v, c};
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    EXPECT_EQ(solution.isLongPressedName("alex", "aaleex"), true);
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.isLongPressedName("saeed", "ssaaedd"), false);
}