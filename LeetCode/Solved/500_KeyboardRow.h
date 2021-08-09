#pragma once
#include "Common.h"

class Solution
{
public:
    vector<string> findWords(vector<string> &words)
    {
        vector<string> result;
        for (auto &word : words)
        {
            if (canType(word))
            {
                result.emplace_back(word);
            }
        }
        return result;
    }

private:
    bool canType(string_view word)
    {
        bool result = true;
        int rowIndex = -1;
        for (auto c : word)
        {
            int temp = getRowIndex(tolower(c));
            if (rowIndex == -1)
            {
                rowIndex = temp;
            }
            else if (rowIndex != temp)
            {
                result = false;
                break;
            }
        }
        return result;
    }
    int getRowIndex(char c)
    {
        static string row1 = "qwertyuiop";
        static string row2 = "asdfghjkl";
        static string row3 = "zxcvbnm";
        if (row1.find(c) != string::npos)
        {
            return 0;
        }
        else if (row2.find(c) != string::npos)
        {
            return 1;
        }
        else
        {
            return 2;
        }
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<string> words = {"Hello", "Alaska", "Dad", "Peace"};
    vector<string> output = {"Alaska", "Dad"};
    EXPECT_EQ(solution.findWords(words), output);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<string> words = {"omk"};
    vector<string> output = {};
    EXPECT_EQ(solution.findWords(words), output);
}

TEST_F(LeetCodeTest, Example3)
{
    vector<string> words = {"adsdf", "sfd"};
    vector<string> output = {"adsdf", "sfd"};
    EXPECT_EQ(solution.findWords(words), output);
}
