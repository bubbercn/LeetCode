#pragma once
#include "Common.h"

class Solution
{
public:
    int kSimilarity(string_view s1, string_view s2)
    {
        string temp1;
        string temp2;
        for (int i = 0; i < s1.length(); i++)
        {
            if (s1[i] != s2[i])
            {
                temp1 += s1[i];
                temp2 += s2[i];
            }
        }

        if (temp1.empty())
            return 0;

        int result = numeric_limits<int>::max();
        char c = temp1[0];
        for (int i = 0; i < temp2.length(); i++)
        {
            if (temp2[i] == c)
            {
                if (i != 0)
                {
                    string temp(temp2);
                    swap(temp[i], temp[0]);
                    result = min(result, kSimilarity(temp1.substr(1), temp.substr(1)) + 1);
                }
                else
                {
                    result = min(result, kSimilarity(temp1.substr(1), temp2.substr(1)));
                }
            }
        }
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
    EXPECT_EQ(solution.kSimilarity("ab", "ba"), 1);
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.kSimilarity("abc", "bca"), 2);
}

TEST_F(LeetCodeTest, Failure1)
{
    EXPECT_EQ(solution.kSimilarity("abac", "baca"), 2);
}

TEST_F(LeetCodeTest, Failure2)
{
    EXPECT_EQ(solution.kSimilarity("abcdeabcdeabcdeabcde", "aaaabbbbccccddddeeee"), 8);
}