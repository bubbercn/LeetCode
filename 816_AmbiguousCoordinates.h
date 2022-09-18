#pragma once
#include "Common.h"

class Solution
{
public:
    vector<string> ambiguousCoordinates(string_view s)
    {
        int n = s.length();
        vector<string> result;
        for (int i = 1; i < n - 2; i++)
        {
            string_view left = s.substr(1, i);
            string_view right = s.substr(i + 1, n - 2 - i);
            vector<string> leftCollection = split(left);
            vector<string> rightCollection = split(right);
            for (auto& x : leftCollection)
            {
                for (auto& y : rightCollection)
                {
                    string temp = "(";
                    temp += x;
                    temp += ", ";
                    temp += y;
                    temp += ")";
                    result.emplace_back(temp);
                }
            }
        }

        return result;
    }
private:
    vector<string> split(string_view s)
    {
        vector<string> result;      
              
        for (int i = 1; i < s.length(); i++)
        {
            string_view left = s.substr(0, i);
            if (!isValid(left))
                continue;
            string_view right = s.substr(i);
            if (!isValidf(right))
                continue;
            string temp(left);
            temp += '.';
            temp += right;
            result.emplace_back(temp);
        }

        if (isValid(s))
            result.emplace_back(string(s));
            
        return result;
    }

    bool isValid(string_view s)
    {
        if (s[0] == '0' && s.length() > 1)
            return false;
        return true;
    }

    bool isValidf(string_view s)
    {
        return *s.rbegin() != '0';
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<string> output = {"(1, 2.3)", "(1, 23)", "(1.2, 3)", "(12, 3)"};
    EXPECT_EQ(solution.ambiguousCoordinates("(123)"), output);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<string> output = {"(0, 1.23)", "(0, 12.3)", "(0, 123)", "(0.1, 2.3)", "(0.1, 23)", "(0.12, 3)"};
    EXPECT_EQ(solution.ambiguousCoordinates("(0123)"), output);
}

TEST_F(LeetCodeTest, Example3)
{
    vector<string> output = {"(0, 0.011)", "(0.001, 1)"};
    EXPECT_EQ(solution.ambiguousCoordinates("(00011)"), output);
}