#pragma once
#include "Common.h"

class Solution
{
public:
    int compress(vector<char> &chars)
    {
        int result = 0;
        int count = 0;
        for (int i = 0; i < chars.size(); i++)
        {
            if (i > 0 && chars[i] != chars[i - 1])
            {
                result += append(&chars[result], chars[i - 1], count);
                count = 0;
            }
            count++;
        }
        result += append(&chars[result], *chars.rbegin(), count);
        return result;
    }

private:
    int  append(char *source, char value, int count)
    {
        *source++ = value;
        string temp = count == 1 ? "" : to_string(count);
        for (int i = 0; i < temp.length(); i++)
            *source++ = temp[i];
        return temp.length() + 1;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<char> chars = {'a', 'a', 'b', 'b', 'c', 'c', 'c'};
    EXPECT_EQ(solution.compress(chars), 6);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<char> chars = {'a'};
    EXPECT_EQ(solution.compress(chars), 1);
}

TEST_F(LeetCodeTest, Example3)
{
    vector<char> chars = {'a', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b'};
    EXPECT_EQ(solution.compress(chars), 4);
}

TEST_F(LeetCodeTest, Example4)
{
    vector<char> chars = {'a', 'a', 'a', 'b', 'b', 'a', 'a'};
    EXPECT_EQ(solution.compress(chars), 6);
}