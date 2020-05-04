#pragma once
#include "Common.h"

class Solution
{
public:
    vector<vector<string>> partition(string s)
    {
        return helper(s, 0, s.length());
    }

private:
    vector<vector<string>> helper(const string &s, size_t begin, size_t end)
    {
        if (begin == end)
            return {};

        vector<vector<string>> result;
        for (size_t i = begin + 1; i <= end; i++)
        {
            if (!isPalindrome(s, begin, i))
                continue;

            if (i < end)
            {
                auto subResult = helper(s, i, end);
                for (auto j : subResult)
                {
                    vector<string> temp;
                    temp.emplace_back(s.substr(begin, i - begin));
                    temp.insert(temp.end(), j.begin(), j.end());
                    if (!temp.empty())
                       result.emplace_back(temp);
                }
            }
            else
            {
                vector<string> temp;
                temp.emplace_back(s.substr(begin, i - begin));
                result.emplace_back(temp);
            }
        }

        return result;
    }

    bool isPalindrome(const string &s, size_t begin, size_t end)
    {
        while (begin < end)
        {
            if (s[begin] != s[end - 1])
                return false;

            begin++;
            end--;
        }
        return true;
    }
};

void Test()
{
    Solution solution;
    auto result = solution.partition("aab");
    result = solution.partition("cdd");
}