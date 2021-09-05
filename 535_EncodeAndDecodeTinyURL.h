#pragma once
#include "Common.h"

class Solution
{
public:
    // Encodes a URL to a shortened URL.
    string encode(string longUrl)
    {
        return longUrl;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl)
    {
        return shortUrl;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    string longURL = "https://leetcode.com/problems/design-tinyurl";
    string shortURL = solution.encode(longURL);
    EXPECT_EQ(solution.decode(shortURL), longURL);
}