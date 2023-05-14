#pragma once
#include "Common.h"

class Solution
{
public:
    vector<string> reorderLogFiles(vector<string> &logs)
    {
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