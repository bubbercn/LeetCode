#pragma once
#include "Common.h"

class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        unordered_map<char, char> map1;
        unordered_map<char, char> map2;
        for (int i = 0; i < s.length(); i++)
        {
            auto temp = map1.emplace(s[i], t[i]);
            if (!temp.second && t[i] != map1[s[i]])
                return false;

            temp = map2.emplace(t[i], s[i]);
            if (!temp.second && s[i] != map2[t[i]])
                return false;
        }

        return true;
    }
};

void Test()
{
    Solution solution;
    assert(solution.isIsomorphic("egg", "add") == true);
    assert(solution.isIsomorphic("foo", "bar") == false);
    assert(solution.isIsomorphic("paper", "title") == true);
}