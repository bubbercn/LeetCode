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
        
        if (s1.length() + s2.length() != s3.length())
            return false;
        
        int i = 0;
        int match1= 0;
        int match2 = 0;
        stack<tuple<int, int, int>> state;
        while (i < s3.length())
        {
            if (s3[i] == s1[match1])
            {
                if (s3[i] == s2[match2])
                {
                    state.emplace(i + 1, match1, match2 + 1);
                }
                match1++;
                i++;
            }
            else if (s3[i] == s2[match2])
            {
                if (s3[i] == s1[match1])
                {
                    state.emplace(i + 1, match1 + 1, match2);
                }
                match2++;
                i++;
            }
            else
            {
                if (state.empty())
                {
                    return false;
                }
                else
                {
                    i = get<0>(state.top());
                    match1 = get<1>(state.top());
                    match2 = get<2>(state.top());
                    state.pop();
                }
            }
        }
        
        return true;
    }
};

void Test()
{
    Solution solution;
    assert(solution.isInterleave("aabcc", "dbbca", "aadbbcbcac"));
    assert(!solution.isInterleave("aabcc", "dbbca", "aadbbbaccc"));
    assert(!solution.isInterleave("a", "b", "a"));
    assert(solution.isInterleave("aa", "ab", "aaba"));
    
//    assert(!solution.isInterleave("bbbbbabbbbabaababaaaabbababbaaabbabbaaabaaaaababbbababbbbbabbbbababbabaabababbbaabababababbbaaababaa",
//                                  "babaaaabbababbbabbbbaabaabbaabbbbaabaaabaababaaaabaaabbaaabaaaabaabaabbbbbbbbbbbabaaabbababbabbabaab",
//                                  "babbbabbbaaabbababbbbababaabbabaabaaabbbbabbbaaabbbaaaaabbbbaabbaaabababbaaaaaabababbababaababbababbbababbbbaaaabaabbabbaaaaabbabbaaaabbbaabaaabaababaababbaaabbbbbabbbbaabbabaabbbbabaaabbababbabbabbab"));
}
