#pragma once
#include "Common.h"

class Solution
{
public:
    int findLUSlength(vector<string> &strs)
    {
        lookup.clear();

        sort(strs.begin(), strs.end(), [](const string &s1, const string &s2)
             { return s1.length() > s2.length(); });

        int result = 0;
        unordered_map<string_view, int> strMap;
        int uniqueCount = 0;
        for (const auto &s : strs)
        {
            if (strMap.empty())
            {
                strMap.emplace(s, 1);
                result = s.length();
                uniqueCount++;
            }
            else if (result == s.length())
            {
                auto [it, inserted] = strMap.emplace(s, 1);
                if (inserted)
                {
                    uniqueCount++;
                }
                else if (it->second++ == 1 && --uniqueCount == 0)
                {
                    result = -1;
                }
            }
            else
            {
                if (result != -1)
                    break;

                if (!helper(strMap, s))
                {
                    result = s.length();
                    strMap.emplace(s, 1);
                    uniqueCount++;
                }
            }
        }

        return result;
    }

private:
    unordered_map<string_view, unordered_map<string_view, bool>> lookup;
    bool helper(unordered_map<string_view, int> &strSet, string_view t)
    {
        for (auto &[str, count] : strSet)
        {
            if (isSubstring(str, t))
                return true;
        }
        return false;
    }

    bool isSubstring(string_view s, string_view t)
    {
        if (auto i = lookup.find(s); i != lookup.end())
        {
            if (auto j = i->second.find(t); j != i->second.end())
            {
                return j->second;
            }
        }
        bool result = true;
        int pos = 0;
        for (auto c : t)
        {
            pos = s.find_first_of(c, pos);
            if (pos == string::npos)
            {
                result = false;
                break;
            }
            pos++;
        }
        lookup.insert({s, {{t, result}}});
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
    vector<string> strs = {"aba", "cdc", "eae"};
    EXPECT_EQ(solution.findLUSlength(strs), 3);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<string> strs = {"aaa", "aaa", "aa"};
    EXPECT_EQ(solution.findLUSlength(strs), -1);
}

TEST_F(LeetCodeTest, Case1)
{
    vector<string> strs = {"aaa", "aaa", "aa", "ab"};
    EXPECT_EQ(solution.findLUSlength(strs), 2);
}

TEST_F(LeetCodeTest, Case2)
{
    vector<string> strs = {"aaa", "aaa", "aa", "ab", "ab", "a"};
    EXPECT_EQ(solution.findLUSlength(strs), -1);
}

TEST_F(LeetCodeTest, Failure1)
{
    vector<string> strs = {"aabbcc", "aabbcc", "c", "e", "aabbcd"};
    EXPECT_EQ(solution.findLUSlength(strs), 6);
}

TEST_F(LeetCodeTest, Failure2)
{
    vector<string> strs = {"a", "b", "c", "d", "e", "f", "a", "b", "c", "d", "e", "f"};
    EXPECT_EQ(solution.findLUSlength(strs), -1);
}

TEST_F(LeetCodeTest, Failure3)
{
    vector<string> strs = {"a", "b", "c", "d", "e", "f", "a", "b", "c", "d", "e"};
    EXPECT_EQ(solution.findLUSlength(strs), 1);
}