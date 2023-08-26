#pragma once
#include "Common.h"

class Solution
{
public:
    string mostCommonWord(string_view paragraph, vector<string> &banned)
    {
        unordered_set<string> ban(banned.begin(), banned.end());
        unordered_map<string, int> lookup;
        int max = 0;
        string result;
        size_t begin = string::npos;
        for (size_t i = 0; i < paragraph.length(); i++)
        {
            if (paragraph[i] >= 'a' && paragraph[i] <= 'z' || paragraph[i] >= 'A' && paragraph[i] <= 'Z')
            {
                if (begin == string::npos)
                {
                    begin = i;
                }
            }
            else if (begin != string::npos)
            {
                string temp(paragraph.substr(begin, i - begin));
                for (auto &c : temp)
                {
                    c = tolower(c);
                }
                if (ban.count(temp) == 0)
                {
                    int &count = lookup[temp];
                    count++;
                    if (count > max)
                    {
                        max = count;
                        result = temp;
                    }
                }
                begin = string::npos;
            }
        }
        if (begin != string::npos)
        {
            string temp(paragraph.substr(begin));
            for (auto &c : temp)
            {
                c = tolower(c);
            }
            if (ban.count(temp) == 0)
            {
                int &count = lookup[temp];
                count++;
                if (count > max)
                {
                    max = count;
                    result = temp;
                }
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
    vector<string> banned = {"hit"};
    EXPECT_EQ(solution.mostCommonWord("Bob hit a ball, the hit BALL flew far after it was hit.", banned), "ball");
}

TEST_F(LeetCodeTest, Example2)
{
    vector<string> banned = {};
    EXPECT_EQ(solution.mostCommonWord("a.", banned), "a");
}