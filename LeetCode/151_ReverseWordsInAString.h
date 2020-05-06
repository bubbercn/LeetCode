#pragma once
#include "Common.h"

class Solution
{
public:
    string reverseWords(string s)
    {
        int cur = 0, wordBegin = 0;
        bool isInWord = false;
        for (size_t i = 0; i < s.length(); i++)
        {
            if (isInWord)
            {
                if (s[i] == ' ')
                {
                    isInWord = false;
                    reverse(s, wordBegin, cur -1);
                }
                s[cur++] = s[i];
            }
            else
            {
                if (s[i] == ' ')
                {
                    continue;
                }
                else
                {
                    isInWord = true;
                    wordBegin = cur;
                    s[cur++] = s[i];
                }
            }
        }
        if (cur - 1 >= 0 && s[cur - 1] == ' ')
        {
            cur--;
        }
        else
        {
            reverse(s, wordBegin, cur - 1);
        }
        if (cur < s.length())
        {
            s[cur] = '\0';
        }
        reverse(s, 0, cur - 1);

        return s.c_str();
    }
private:
    void reverse(string& s, int begin, int end)
    {
        while (begin < end)
        {
            s[begin] ^= s[end];
            s[end] ^= s[begin];
            s[begin] ^= s[end];
            begin++;
            end--;
        }
    }
};

void Test()
{
    Solution solution;
    
    assert(solution.reverseWords("the sky is blue") == "blue is sky the");
    assert(solution.reverseWords("  hello world!  ") == "world! hello");
    assert(solution.reverseWords("a good   example") == "example good a");
    assert(solution.reverseWords("") == "");
    assert(solution.reverseWords(" ") == "");
}
