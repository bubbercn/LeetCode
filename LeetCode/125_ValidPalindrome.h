#pragma once
#include "Common.h"

class Solution
{
public:
    bool isPalindrome(string s)
    {
        vector<char> str;
        str.reserve(s.length());
        
        int length = 0;
        for (const auto& i : s)
        {
            if ((i >= 'a' && i <= 'z') || (i >= '0' && i <= '9'))
            {
                str.emplace_back(i);
                length++;
            }
            else if (i >= 'A' && i <= 'Z')
            {
                str.emplace_back(i + 'a' - 'A');
                length++;
            }
        }
        
        for (int i = 0; i < length / 2; i++)
        {
            if (str[i] != str[length - 1 - i])
                return false;
        }
        
        return true;
    }
};

void Test()
{
    Solution solution;
    
    assert(solution.isPalindrome("A man, a plan, a canal: Panama"));
    assert(!solution.isPalindrome("race a car"));
}
