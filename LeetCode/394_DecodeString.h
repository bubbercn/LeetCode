#pragma once
#include "Common.h"

class Solution
{
public:
    string decodeString(string s)
    {
        stack<int> repeatCounts;
        int begin = -1;
        int end = -1;
        stack<stringstream> decodedString;
        decodedString.emplace();
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '[')
            {
                decodedString.emplace();
            }
            else if (s[i] == ']')
            {
                string repeat = decodedString.top().str();
                decodedString.pop();
                int repeatCount = repeatCounts.top();
                repeatCounts.pop();
                for (int i = 0; i < repeatCount; i++)
                {
                    decodedString.top() << repeat;
                }
            }
            else if (isNumeric(s[i]))
            {
                begin = i;
                end =  s.find('[', begin);
                repeatCounts.emplace(stoi(s.substr(begin, end - begin)));
                i = end - 1;
            }
            else
            {
                decodedString.top() << s[i];
            }
        }
        return decodedString.top().str();
    }
private:
    bool isNumeric(char c)
    {
        return c >= '0' && c <= '9';
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    EXPECT_EQ(solution.decodeString("3[a]2[bc]"), "aaabcbc");
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.decodeString("3[a2[c]]"), "accaccacc");
}

TEST_F(LeetCodeTest, Example3)
{
    EXPECT_EQ(solution.decodeString("2[abc]3[cd]ef"), "abcabccdcdcdef");
}

TEST_F(LeetCodeTest, Example4)
{
    EXPECT_EQ(solution.decodeString("abc3[cd]xyz"), "abccdcdcdxyz");
}