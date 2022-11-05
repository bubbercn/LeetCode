#pragma once
#include "Common.h"

class Solution
{
public:
    string findReplaceString(string_view s, vector<int> &indices, vector<string> &sources, vector<string> &targets)
    {
        int n = indices.size();
        using Replacement = tuple<int, string_view, string_view>;
        vector<Replacement> replacements(n);
        for (int i = 0; i < n; i++)
        {
            replacements[i] = {indices[i], sources[i], targets[i]};
        }
        sort(replacements.begin(), replacements.end(), [](const Replacement &v1, const Replacement &v2)
             { return get<0>(v1) < get<0>(v2); });
        string result;
        int begin = 0;
        for (auto &[index, source, target] : replacements)
        {
            result += s.substr(begin, index - begin);
            begin = index;
            if (s.substr(index, source.length()) == source)
            {
                result += target;
                begin += source.length();
            }
        }
        result += s.substr(begin, s.length() - begin);
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
    vector<int> indices = {0, 2};
    vector<string> sources = {"a", "cd"};
    vector<string> targets = {"eee", "ffff"};
    EXPECT_EQ(solution.findReplaceString("abcd", indices, sources, targets), "eeebffff");
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> indices = {0, 2};
    vector<string> sources = {"ab", "ec"};
    vector<string> targets = {"eee", "ffff"};
    EXPECT_EQ(solution.findReplaceString("abcd", indices, sources, targets), "eeecd");
}

TEST_F(LeetCodeTest, Failure1)
{
    vector<int> indices = {3, 5, 1};
    vector<string> sources = {"kg", "ggq", "mo"};
    vector<string> targets = {"s", "so", "bfr"};
    EXPECT_EQ(solution.findReplaceString("vmokgggqzp", indices, sources, targets), "vbfrssozp");
}