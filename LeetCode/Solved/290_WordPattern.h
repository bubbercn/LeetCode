#pragma once
#include "Common.h"

class Solution
{
public:
    bool wordPattern(string pattern, string str)
    {
        char *input = str.empty() ? nullptr : &str[0];
        unordered_map<char, string> lookup;
        set<string> strSet;
        char *token = nullptr;
        if (input)
        {
            token = strtok(input, " ");
        }
        for (auto c : pattern)
        {
            if (token == nullptr)
                return false;

            auto it = lookup.find(c);
            if (it != lookup.end())
            {
                if (it->second != token)
                    return false;
            }
            else
            {
                if (!strSet.emplace(token).second)
                    return false;
                lookup.emplace(c, token);
            }
            token = strtok(nullptr, " ");
        }
        if (token != nullptr)
            return false;
        return true;
    }
};

void Test()
{
    Solution solution;
    string pattern, str;

    pattern = "abba";
    str = "dog cat cat dog";
    assert(solution.wordPattern(pattern, str));

    pattern = "abba";
    str = "dog cat cat fish";
    assert(!solution.wordPattern(pattern, str));

    pattern = "aaaa";
    str = "dog cat cat dog";
    assert(!solution.wordPattern(pattern, str));

    pattern = "abba";
    str = "dog dog dog dog";
    assert(!solution.wordPattern(pattern, str));

    pattern = "";
    str = "";
    assert(solution.wordPattern(pattern, str));
}