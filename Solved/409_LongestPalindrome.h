#pragma once
#include "Common.h"

class Solution
{
public:
    int longestPalindrome(string s)
    {
        vector<int> lowerCase(26, 0);
        vector<int> upperCase(26, 0);
        for (auto c : s)
        {
            if (c >= 'a' && c <= 'z')
            {
                lowerCase[c - 'a']++;
            }
            else
            {
                upperCase[c - 'A']++;
            }
        }
        int result = 0;
        bool plusOne = false;

        auto helper = [&result, &plusOne](const vector<int> &letterCount) {
            for (auto i : letterCount)
            {
                result += i - i % 2;
                if (!plusOne)
                {
                    if (i % 2 != 0)
                    {
                        plusOne = true;
                    }
                }
            }
        };

        helper(lowerCase);
        helper(upperCase);

        if (plusOne)
        {
            result++;
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
    EXPECT_EQ(solution.longestPalindrome("abccccdd"), 7);
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.longestPalindrome("a"), 1);
}

TEST_F(LeetCodeTest, Example3)
{
    EXPECT_EQ(solution.longestPalindrome("bb"), 2);
}

TEST_F(LeetCodeTest, Failure1)
{
    EXPECT_EQ(solution.longestPalindrome("AAAAAA"), 6);
}