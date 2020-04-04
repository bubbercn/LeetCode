#pragma once
#include "Common.h"

class Solution
{
public:
    bool isInterleave(string s1, string s2, string s3)
    {
        if (s1.empty())
            return s2 == s3;
        
        if (s2.empty())
            return s1 == s3;
        
        size_t m = s1.length();
        size_t n = s2.length();
        
        if (m + n != s3.length())
            return false;
        
        vector<bool> result(n + 1, false);
        
        for (int i = 0; i <= m; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                if (i == 0 && j == 0)
                {
                    result[j] = true;
                }
                else if (i == 0)
                {
                    result[j] = result[j - 1] && s2[j - 1] == s3[i + j - 1];
                }
                else if (j == 0)
                {
                    result[j] = result[j] && s1[i - 1] == s3[i + j - 1];
                }
                else
                {
                    result[j] = (result[j - 1] && s2[j - 1] == s3[i + j - 1]) || (result[j] && s1[i - 1] == s3[i + j - 1]);
                }
            }
        }
        
        return result[n];
    }
};

void Test()
{
    Solution solution;
    assert(solution.isInterleave("aabcc", "dbbca", "aadbbcbcac"));
    assert(!solution.isInterleave("aabcc", "dbbca", "aadbbbaccc"));
    assert(!solution.isInterleave("a", "b", "a"));
    assert(solution.isInterleave("aa", "ab", "aaba"));
    assert(!solution.isInterleave("bbbbbabbbbabaababaaaabbababbaaabbabbaaabaaaaababbbababbbbbabbbbababbabaabababbbaabababababbbaaababaa",
                                  "babaaaabbababbbabbbbaabaabbaabbbbaabaaabaababaaaabaaabbaaabaaaabaabaabbbbbbbbbbbabaaabbababbabbabaab",
                                  "babbbabbbaaabbababbbbababaabbabaabaaabbbbabbbaaabbbaaaaabbbbaabbaaabababbaaaaaabababbababaababbababbbababbbbaaaabaabbabbaaaaabbabbaaaabbbaabaaabaababaababbaaabbbbbabbbbaabbabaabbbbabaaabbababbabbabbab"));
}
