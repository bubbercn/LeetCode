#pragma once
#include "Common.h"

class Solution
{
public:
    vector<string> reorderLogFiles(vector<string> &logs)
    {
        auto cmp = [](const string &s1, const string &s2)
        {
            auto pos1 = s1.find(' ');
            auto pos2 = s2.find(' ');
            char c1 = s1[pos1 + 1];
            bool isDigit1 = c1 >= '0' and c1 <= '9';
            char c2 = s2[pos2 + 1];
            bool isDigit2 = c2 >= '0' and c2 <= '9';
            if (isDigit1)
            {
                return false;
            }
            else
            {
                if (isDigit2)
                {
                    return true;
                }
                else
                {
                    string p1 = s1.substr(pos1 + 1);
                    string p2 = s2.substr(pos2 + 1);
                    if (p1 == p2)
                    {
                        return s1.substr(0, pos1) < s2.substr(0, pos2);
                    }
                    return p1 < p2;
                }
            }
        };
        stable_sort(logs.begin(), logs.end(), cmp);
        return logs;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<string> logs = {"dig1 8 1 5 1", "let1 art can", "dig2 3 6", "let2 own kit dig", "let3 art zero"};
    vector<string> output = {"let1 art can", "let3 art zero", "let2 own kit dig", "dig1 8 1 5 1", "dig2 3 6"};
    EXPECT_EQ(solution.reorderLogFiles(logs), output);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<string> logs = {"a1 9 2 3 1", "g1 act car", "zo4 4 7", "ab1 off key dog", "a8 act zoo"};
    vector<string> output = {"g1 act car", "a8 act zoo", "ab1 off key dog", "a1 9 2 3 1", "zo4 4 7"};
    EXPECT_EQ(solution.reorderLogFiles(logs), output);
}