#pragma once
#include "Common.h"

class Solution
{
public:
    int kSimilarity(string_view s1, string_view s2)
    {
        if (s1 == s2)
            return 0;
        
        int result = numeric_limits<int>::max();
        char c = s1[0];
        for (int i = 0; i < s2.length(); i++)
        {
            if (s2[i] == c)
            {
                string temp(s2.substr(0, i));
                temp += s2.substr(i + 1);
                result = min(result, kSimilarity(s1.substr(1), temp) + 1);
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
    EXPECT_EQ(solution.kSimilarity("abc", "cba"), 2);
}