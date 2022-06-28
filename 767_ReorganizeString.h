#pragma once
#include "Common.h"

class Solution
{
public:
    string reorganizeString(string_view s)
    {
        vector<int> countLookup(26, 0);
        for (auto c : s)
        {
            int index = c - 'a';
            countLookup[index]++;
        }
        multimap<int, char, greater<int>> count2CharMap;
        for (int i = 0; i < 26; i++)
        {
            if (countLookup[i] != 0)
            {
                count2CharMap.emplace(countLookup[i], 'a' + i);
            }
        }
        int next = 0;
        bool mostCommonHandled = false;
        string result(s.length(), 0);
        while (!count2CharMap.empty())
        {
            int count = count2CharMap.begin()->first;
            char c = count2CharMap.begin()->second;
            while (count > 0)
            {
                if (next >= s.length())
                {
                    if (mostCommonHandled)
                    {
                        next = 1;
                    }
                    else
                    {
                        return {};
                    }
                }
                result[next] = c;
                count--;
                next += 2;
            }
            count2CharMap.erase(count2CharMap.begin());
            mostCommonHandled = true;
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
    EXPECT_EQ(solution.reorganizeString("aab"), "aba");
}

TEST_F(LeetCodeTest, Example2)
{
    EXPECT_EQ(solution.reorganizeString("aaab"), "");
}
