#pragma once
#include "Common.h"

class WordDictionary
{
public:
    /** Initialize your data structure here. */
    WordDictionary()
    {

    }
    
    /** Adds a word into the data structure. */
    void addWord(string word)
    {
        char2StringMaps& index1= idx[word.length()];
        for (int i = 0; i < word.length(); i++)
        {
            if (index1.size() < i + 1)
            {
                index1.push_back({});
            }
            index1[i][word[i]].emplace(word);
        }
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word)
    {
        char2StringMaps& index1= idx[word.length()];
        if (index1.empty())
            return false;
        set<string> result;
        for (int i = 0; i < word.length(); i++)
        {
            if (word[i] != '.')
            {
                unordered_set<string> cur = index1[i][word[i]];
                if (cur.empty())
                    return false;
                
                set<string> temp = set<string>(cur.begin(), cur.end());
                
                if (result.empty())
                {
                    result = temp;
                }
                else
                {
                    set<string> temp2;
                    set_intersection(result.begin(), result.end(), temp.begin(), temp.end(), inserter(temp2, temp2.begin()));
                    result.swap(temp2);
                    if (result.empty())
                        return false;
                }
            }
        }
        return true;
    }
private:
    
    using char2StringMap = unordered_map<char, unordered_set<string>>;
    using char2StringMaps = vector<char2StringMap>;
    unordered_map<size_t, char2StringMaps> idx;
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */

void Test()
{
    WordDictionary dic;
    dic.search("a");
    dic.addWord("bad");
    dic.addWord("dad");
    dic.addWord("mad");
    assert(!dic.search("pad"));
    assert(dic.search("bad"));
    assert(dic.search(".ad"));
    assert(dic.search("b.."));
}
