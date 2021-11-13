#pragma once
#include "Common.h"

class Solution
{
public:
    int minDistance(string_view word1, string_view word2)
    {
        int result = 0;
        for (int i = 0; i < word1.length(); i++)
        {
            auto pos = word2.find(word1[i]);
            if (pos == word1.npos)
            {
                result++;
            }
            else
            {
                result += pos;

                if (pos + 1 == word2.length())
                {
                    result += word1.length() - i - 1;
                    return result;
                }
                
                if (i + 1 == word1.length())
                {
                    result += word2.length() - pos - 1;
                    return result;
                    
                }
                
                result += min(minDistance(word1, word2.substr(pos + 1)), minDistance(word1.substr(i + 1), word2.substr(pos + 1)));
                return result;
            }
        }
        result += word2.length();
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
    EXPECT_EQ(solution.minDistance("sea", "eat"), 2);
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.minDistance("leetcode", "etco"), 4);
}

TEST_F(LeetCodeTest, Case1)
{
    EXPECT_EQ(solution.minDistance("a", "b"), 2);
}

TEST_F(LeetCodeTest, Failure1)
{
    EXPECT_EQ(solution.minDistance("sea", "ate"), 4);
}

TEST_F(LeetCodeTest, Failure2)
{
    EXPECT_EQ(solution.minDistance("mart", "karma"), 5);
}

TEST_F(LeetCodeTest, Failure3)
{
    EXPECT_EQ(solution.minDistance("intention", "execution"), 8);
}