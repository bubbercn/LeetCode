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
        Index* curIndex = &index;
        for (int i = 0; i < word.length(); i++)
        {
            auto it = curIndex->emplace(word[i], new IndexNode());
            curIndex = &(it.first->second->childIndexNodes);
            if (i == word.length() - 1)
            {
                it.first->second->hasWord = true;
            }
        }
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word)
    {
        return search(index, word);
    }
private:
    struct IndexNode;
    using Index = unordered_map<char, unique_ptr<IndexNode>>;
    struct IndexNode
    {
        bool hasWord = false;
        Index childIndexNodes;
    };
    Index index;
    
    bool search(Index& index, const string& word)
    {
        if (word.empty())
            return false;
        
        if (word[0] == '.')
        {
            for (auto& i : index)
            {
                if (word.length() == 1)
                {
                    if (i.second->hasWord)
                    {
                        return true;
                    }
                    else
                    {
                        continue;
                    }
                }
                else
                {
                    if (search(i.second->childIndexNodes, word.substr(1)))
                    {
                        return true;
                    }
                    else
                    {
                        continue;
                    }
                }
            }
            return false;
        }
        else
        {
            auto it = index.find(word[0]);
            if (it == index.end())
            {
                return false;
            }
            if (word.length() == 1)
            {
                return it->second->hasWord;
            }
            else
            {
                return search(it->second->childIndexNodes, word.substr(1));
            }
        }
    }
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
