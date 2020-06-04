#pragma once
#include "Common.h"

class Trie
{
public:
    /** Initialize your data structure here. */
    Trie()
    {
    }

    /** Inserts a word into the trie. */
    void insert(string word)
    {
        if (words.insert(word).second)
        {
            for (int i = 1; i <= word.length(); i++)
            {
                prefixes.insert(word.substr(0, i));
            }
        }
    }

    /** Returns if the word is in the trie. */
    bool search(string word)
    {
        return words.find(word) != words.end();
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix)
    {
        return prefixes.find(prefix) != prefixes.end();
    }

private:
    unordered_set<string> words;
    unordered_set<string> prefixes;
};

void Test()
{
    Trie test;
    test.insert("apple");
}