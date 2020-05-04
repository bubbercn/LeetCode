#pragma once
#include "Common.h"

class Solution
{
public:
    vector<string> wordBreak(string s, vector<string>& wordDict)
    {
        size_t n = s.length();
        unordered_set<string> dictionary(wordDict.begin(), wordDict.end());
        vector<list<string>> result(n, list<string>());
        
        for (int i = 0; i < n; i++)
        {
            for (int j = -1; j < i; j++)
            {
                if (j == -1)
                {
                    if (dictionary.find(s.substr(0, i + 1)) != dictionary.end())
                    {
                        string temp = s.substr(0, i + 1);
                        if (!temp.empty())
                        {
                            result[i].emplace_back(std::move(temp));
                        }
                    }
                }
                else
                {
                    if (!result[j].empty() && dictionary.find(s.substr(j + 1, i - j)) != dictionary.end())
                    {
                        for (auto str : result[j])
                        {
                            string temp = str + " " + s.substr(j + 1, i - j);
                            if (!temp.empty())
                            {
                                result[i].emplace_back(std::move(temp));
                            }
                        }
                    }
                }
            }
        }
        
        return {result[n - 1].begin(), result[n - 1].end()};
    }
};

void Test()
{
    Solution solution;
    string s;
    vector<string> wordDict;
    
    s = "catsanddog";
    wordDict = {"cat", "cats", "and", "sand", "dog"};
    solution.wordBreak(s, wordDict);
    
    s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
    wordDict = {"a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"};
    solution.wordBreak(s, wordDict);
}
