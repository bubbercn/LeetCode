#pragma once
#include "Common.h"

class Solution {
public:
    int lengthOfLastWord(string s)
    {
        bool foundLast = false;
        int result = 0;
        for (auto i = s.rbegin(); i != s.rend(); i++)
        {
            if (foundLast)
            {
                if (*i == ' ')
                {
                    break;
                }
                else
                {
                    result++;
                }
            }
            else
            {
                if (*i == ' ')
                {
                    continue;
                }
                else
                {
                    foundLast = true;
                    result++;
                }
            }
        }
        return result;
    }
};

void Test()
{
    Solution solution;
    string input = "Hello World";
    assert(solution.lengthOfLastWord(input) == 5);
}
