#pragma once
#include "Common.h"

class Solution
{
public:
    vector<vector<int>> palindromePairs(vector<string> &words)
    {
        vector<vector<int>> result;
        unordered_map<string, int> lookup;
        for (int i = 0; i < words.size(); i++)
        {
            lookup.emplace(words[i], i);
        }

        for (int i = 0; i < words.size(); i++)
        {
            for (int j = 0; j < words[i].length(); j++)
            {
                if (isPalindrome(words[i].substr(j)))
                {
                    string target = words[i].substr(0, j);
                    reverse(target.begin(), target.end());
                    auto it = lookup.find(target);
                    if (it != lookup.end() && it->second != i)
                    {
                        result.push_back({i, it->second});
                    }
                }
            }

            for (int j = 0; j <= words[i].length(); j++)
            {
                if (isPalindrome(words[i].substr(0, j)))
                {
                    string target = words[i].substr(j);
                    reverse(target.begin(), target.end());
                    auto it = lookup.find(target);
                    if (it != lookup.end() && it->second != i)
                    {
                        result.push_back({it->second, i});
                    }
                }
            }
        }

        return result;
    }

private:
    bool isPalindrome(const string &word)
    {
        if (word.empty())
            return true;
        int begin = 0;
        int end = word.length() - 1;
        while (begin < end)
        {
            if (word[begin++] != word[end--])
            {
                return false;
            }
        }
        return true;
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