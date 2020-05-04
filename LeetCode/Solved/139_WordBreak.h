#pragma once
#include "Common.h"

class Solution
{
public:
    bool wordBreak(string s, vector<string>& wordDict)
    {
        size_t n = s.length();
        unordered_set<string> dictionary(wordDict.begin(), wordDict.end());
        vector<bool> result(n, false);
        
        for (int i = 0; i < n; i++)
        {
            for (int j = -1; j < i; j++)
            {
                if (j == -1)
                {
                    if (dictionary.find(s.substr(0, i + 1)) != dictionary.end())
                    {
                        result[i] = true;
                        break;
                    }
                }
                else
                {
                    if (result[j] && dictionary.find(s.substr(j + 1, i - j)) != dictionary.end())
                    {
                        result[i] = true;
                        break;
                    }
                }
            }
        }
        
        return result[n - 1];
    }
};

void Test()
{
    Solution solution;
    string s;
    vector<string> wordDict;
    
    s = "leetcode";
    wordDict = {"leet", "code"};
    assert(solution.wordBreak(s, wordDict) == true);
 
    s = "applepenapple";
    wordDict = {"apple", "pen"};
    assert(solution.wordBreak(s, wordDict) == true);
    
    s = "catsandog";
    wordDict = {"cats", "dog", "sand", "and", "cat"};
    assert(solution.wordBreak(s, wordDict) == false);
}
