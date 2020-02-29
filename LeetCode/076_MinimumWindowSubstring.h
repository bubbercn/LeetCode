#pragma once
#include "Common.h"

class Solution {
public:
    string minWindow(string s, string t)
    {
        size_t begin = 0;
        size_t end = 0;
        string result = "";
        bool move_begin = false;
        if (s.empty())
            return "";
        
        if (t.empty())
            return s.substr(0, 1);
    
        init(t);
        
        while (begin <= end && end <= s.length())
        {
            if (check())
            {
                move_begin = true;
                if (result.empty())
                {
                    result = s.substr(begin, end - begin);
                }
                else
                {
                    if (end - begin < result.length())
                    {
                        result = s.substr(begin, end - begin);
                    }
                }
            }
            else
            {
                move_begin = false;
            }
            if (move_begin)
            {
                auto i = lookup.find(s[begin++]);
                if (i != lookup.end())
                    i->second++;
            }
            else
            {
                auto i = lookup.find(s[end++]);
                if (i != lookup.end())
                    i->second--;
            }
        }
        
        return result;
    }
private:
    unordered_map<char, int> lookup;
    void init(string t)
    {
        for (auto i = t.begin(); i != t.end(); i++)
        {
            lookup[*i]++;
        }
    }
    bool check()
    {
        for (auto i = lookup.begin(); i != lookup.end(); i++)
        {
            if (i->second > 0)
                return false;
        }
        return true;
    }
};

void Test()
{
    Solution solution;
    string S = "ADOBECODEBANC", T = "ABC";
    assert(solution.minWindow(S, T) == "BANC");
    assert(solution.minWindow(S, "") == "A");
    assert(solution.minWindow("", "ABC") == "");
}
