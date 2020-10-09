#pragma once
#include "Common.h"

class Solution
{
public:
    vector<vector<int>> palindromePairs(vector<string> &words)
    {
        vector<vector<int>> result;
        for (int i = 0; i < words.size(); i++)
        {
            for (int j = 0; j < words.size(); j++)
            {
                if (i == j)
                    continue;
                string temp = words[i] + words[j];
                auto hash1 = hash<string>()(temp);
                reverse(temp.begin(), temp.end());
                auto hash2 = hash<string>()(temp);
                if (hash1 == hash2)
                    result.push_back({i, j});
            }
        }
        return result;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<string> words = {"abcd", "dcba", "lls", "s", "sssll"};
    vector<vector<int>> output = {{0, 1}, {1, 0}, {2, 4}, {3, 2}};
    EXPECT_EQ(solution.palindromePairs(words), output);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<string> words = {"bat", "tab", "cat"};
    vector<vector<int>> output = {{0, 1}, {1, 0}};
    EXPECT_EQ(solution.palindromePairs(words), output);
}

TEST_F(LeetCodeTest, Example3)
{
    vector<string> words = {"a", ""};
    vector<vector<int>> output = {{0, 1}, {1, 0}};
    EXPECT_EQ(solution.palindromePairs(words), output);
}