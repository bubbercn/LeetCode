#pragma once
#include "Common.h"

class Solution
{
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string> &words)
    {
        auto cmp = [](const string &s1, const string &s2)
        {
            if (s1.length() == s2.length())
                return s1 < s2;
            return s1.length() < s2.length();
        };
        sort(words.begin(), words.end(), cmp);
        DictionaryNode root{false, {}};
        vector<string> result;
        for (const auto &word : words)
        {
            DictionaryNode *parent = &root;
            bool isConcatenated = false;
            for (int i = 0; i < word.length(); i++)
            {
                auto [it, inserted] = parent->children.emplace(word[i], nullptr);
                if (inserted)
                {
                    it->second.reset(new DictionaryNode{i == word.length() - 1, {}});
                }
                else
                {
                    if (!isConcatenated && it->second.get()->exitWord)
                    {
                        isConcatenated = Solution::isConcatenated(&root, word.substr(i + 1));
                        if (isConcatenated)
                            result.emplace_back(word);
                    }
                }
                parent = it->second.get();
            }
        }
        return result;
    }

private:
    struct DictionaryNode
    {
        bool exitWord;
        unordered_map<char, unique_ptr<DictionaryNode>> children;
    };
    bool isConcatenated(DictionaryNode *root, const string &word)
    {
        static unordered_map<string, bool> lookup;
        if (auto i = lookup.find(word); i != lookup.end())
        {
            return i->second;
        }
        DictionaryNode* parent = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (auto it = parent->children.find(word[i]); it == parent->children.end())
            {
                lookup[word] = false;
                return false;
            }
            else
            {
                if (it->second.get()->exitWord && (i == word.length() - 1 || isConcatenated(root, word.substr(i + 1))))
                {
                    lookup[word] = true;
                    return true;
                }
                parent = it->second.get();
            }
        }
        lookup[word] = true;
        return true;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<string> words = {"cat", "cats", "catsdogcats", "dog", "dogcatsdog", "hippopotamuses", "rat", "ratcatdogcat"};
    vector<string> output = {"catsdogcats", "dogcatsdog", "ratcatdogcat"};
    EXPECT_EQ(solution.findAllConcatenatedWordsInADict(words), output);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<string> words = {"cat", "dog", "catdog"};
    vector<string> output = {"catdog"};
    EXPECT_EQ(solution.findAllConcatenatedWordsInADict(words), output);
}