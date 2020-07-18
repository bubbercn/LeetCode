#pragma once
#include "Common.h"

class Solution
{
public:
    bool isAnagram(const string &s, const string &t)
    {
        return getMap(s) == getMap(t);
    }

private:
    unordered_map<char, int> getMap(const string &s)
    {
        unordered_map<char, int> result;
        for (const auto &c : s)
        {
            result[c]++;
        }
        return result;
    }
};

void Test()
{
    Solution solution;
    assert(solution.isAnagram("anagram", "nagaram"));
    assert(!solution.isAnagram("rat", "car"));
}