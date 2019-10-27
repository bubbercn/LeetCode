#pragma once
#include "Common.h"

class Solution {
public:
    bool isMatch(string s, string p) {
        int i = 0, j = 0, iStar = -1, jStar = -1;
        while (i < s.length())
        {
            if (j < p.length() && (s[i] == p[j] || p[j] == '?'))
            {
                ++i; ++j;
            }
            else if (j < p.length() && p[j] == '*')
            {
                iStar = i;
                jStar = j++;
            }
            else if (iStar >= 0)
            {
                i = ++iStar;
                j = jStar + 1;
            }
            else
            {
                return false;
            }
        }
        while (j < p.length() && p[j] == '*')
        {
            ++j;
        }
        return j == p.length();
    }
};

void Test()
{
    Solution solution;
    assert(solution.isMatch("", "*") == true);
    assert(solution.isMatch("aa", "a") == false);
    assert(solution.isMatch("aa", "*") == true);
    assert(solution.isMatch("cb", "?a") == false);
    assert(solution.isMatch("adceb", "*a*b") == true);
    assert(solution.isMatch("acdcb", "a*c?b") == false);
    assert(solution.isMatch("abbabaaabbabbaababbabbbbbabbbabbbabaaaaababababbbabababaabbababaabbbbbbaaaabababbbaabbbbaabbbbababababbaabbaababaabbbababababbbbaaabbbbbabaaaabbababbbbaababaabbababbbbbababbbabaaaaaaaabbbbbaabaaababaaaabb", "**aa*****ba*a*bb**aa*ab****a*aaaaaa***a*aaaa**bbabb*b*b**aaaaaaaaa*a********ba*bbb***a*ba*bb*bb**a*b*bb") == false);
}
