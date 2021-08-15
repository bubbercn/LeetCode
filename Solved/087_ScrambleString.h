#pragma once
#include "Common.h"

class Solution
{
public:
    bool isScramble(string s1, string s2)
    {
        if (s1 == s2)
            return true;

        if (s1.size() != s2.size())
            return false;

        return TrySplit(s1, s2);
    }

private:
    bool TrySplit(const string &s1, const string &s2)
    {
        if (s2 == s1)
            return true;

        if (s1.size() == 1)
        {
            return s1 == s2;
        }

        unordered_map<char, size_t> left1;
        unordered_map<char, size_t> right1;

        left1[s1[0]]++;
        for (int i = 1; i < s1.size(); i++)
        {
            right1[s1[i]]++;
        }

        unordered_map<char, size_t> left2;
        unordered_map<char, size_t> right2;

        left2[s2[0]]++;
        for (int i = 1; i < s2.size(); i++)
        {
            right2[s2[i]]++;
        }

        unordered_map<char, size_t> left3;
        unordered_map<char, size_t> right3;

        right3[*s2.rbegin()]++;
        for (int i = 0; i < s2.size() - 1; i++)
        {
            left3[s2[i]]++;
        }

        for (int i = 1; i < s1.size(); i++)
        {
            if (left1 == left2 && right1 == right2)
            {
                if (TrySplit(s1.substr(0, i), s2.substr(0, i)) && TrySplit(s1.substr(i), s2.substr(i)))
                    return true;
            }
            if (left1 == right3 && right1 == left3)
            {
                if (TrySplit(s1.substr(0, i), s2.substr(s2.size() - i)) && TrySplit(s1.substr(i), s2.substr(0, s2.size() - i)))
                    return true;
            }
            left1[s1[i]]++;
            right1[s1[i]]--;
            if (!right1[s1[i]])
            {
                right1.erase(s1[i]);
            }
            left2[s2[i]]++;
            right2[s2[i]]--;
            if (!right2[s2[i]])
            {
                right2.erase(s2[i]);
            }
            left3[s2[s2.size() - i - 1]]--;
            right3[s2[s2.size() - i - 1]]++;
            if (!left3[s2[s2.size() - i - 1]])
            {
                left3.erase(s2[s2.size() - i - 1]);
            }
        }

        return false;
    }
};

void Test()
{
    Solution solution;
    assert(solution.isScramble("great", "rgeat"));
    assert(!solution.isScramble("abcde", "caebd"));
}