#pragma once
#include "Common.h"

class Solution
{
public:
    vector<string> wordBreak(string s, vector<string>& wordDict)
    {
        init(s, wordDict);
        list<string> result = helper(0);
        return {result.begin(), result.end()};
    }
private:
    void init(const string& s, const vector<string>& wordDict)
    {
        N = s.length();
        this->s = s;
        dictionary = unordered_set<string>(wordDict.begin(), wordDict.end());
        lookUp.clear();
    }
    
    list<string> helper(size_t begin)
    {
        string key = s.substr(begin);
        auto it = lookUp.find(key);
        if (it != lookUp.end())
            return it->second;
        
        list<string> result;
        for (size_t len = 1; len <= N - begin; len++)
        {
            string subString = s.substr(begin, len);
            if (dictionary.find(subString) != dictionary.end())
            {
                if (len == N - begin)
                {
                    result.emplace_back(subString);
                }
                else
                {
                    list<string> subResult = helper(begin + len);
                    for (const auto& s : subResult)
                    {
                        string temp = subString;
                        temp += " ";
                        temp += s;
                        result.emplace_back(temp);
                    }
                }
            }
        }
        
        lookUp.emplace(key, result);
        return result;
    }
    
    string s;
    size_t N;
    unordered_set<string> dictionary;
    unordered_map<string, list<string>> lookUp;
};

void Test()
{
    Solution solution;
    string s;
    vector<string> wordDict;
    
    s = "catsanddog";
    wordDict = {"cat", "cats", "and", "sand", "dog"};
    solution.wordBreak(s, wordDict);

    s = "pineapplepenapple";
    wordDict = {"apple", "pen", "applepen", "pine", "pineapple"};
    solution.wordBreak(s, wordDict);

    
    s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
    wordDict = {"a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"};
    solution.wordBreak(s, wordDict);
}
