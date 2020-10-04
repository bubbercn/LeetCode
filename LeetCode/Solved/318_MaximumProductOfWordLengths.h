#pragma once
#include "Common.h"

class Solution
{
public:
    int maxProduct(vector<string> &words)
    {
        vector<int> bitArrays(words.size(), 0);
        int index = 0;
        for (auto& s : words)
        {
            auto& bitArray = bitArrays[index++];
            for (auto c : s)
            {
                bitArray |= (1 << (c - 'a'));
            }
        }

        size_t max = 0;
        for (int i = 0; i < bitArrays.size(); i++)
        {
            for (int j = i + 1; j < bitArrays.size(); j++)
            {
                if ((bitArrays[i] & bitArrays[j]) == 0)
                {
                    max = ::max(max, words[i].length() * words[j].length());
                }
            }
        }

        return max;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<string> input = {"abcw", "baz", "foo", "bar", "xtfn", "abcdef"};
    EXPECT_EQ(solution.maxProduct(input), 16);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<string> input = {"a", "ab", "abc", "d", "cd", "bcd", "abcd"};
    EXPECT_EQ(solution.maxProduct(input), 4);
}

TEST_F(LeetCodeTest, Example3)
{
    vector<string> input = {"a", "aa", "aaa", "aaaa"};
    EXPECT_EQ(solution.maxProduct(input), 0);
}
