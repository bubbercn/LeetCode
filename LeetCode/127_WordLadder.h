#pragma once
#include "Common.h"

class Solution
{
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList)
    {
        init(beginWord, endWord, wordList);
        
        if (dictionary.find(endWord) == dictionary.end())
            return 0;
        
        firstStep(beginWord);
        
        if (bfs())
        {
            return static_cast<int>(length);
        }
        return 0;
    }
private:
    void firstStep(const string& beginWord)
    {
        bfsQueue = queue<size_t>();
        string temp = beginWord;
        for (size_t j = 0; j < beginWord.length(); j++)
        {
            for (char k = 'a'; k <= 'z'; k++)
            {
                if (k == beginWord[j])
                    continue;
                
                temp[j] = k;
                
                if (dictionary.find(temp) != dictionary.end())
                {
                    bfsQueue.emplace(wordIndex[temp]);
                    visited[wordIndex[temp]] = true;
                }
                
                temp[j] = beginWord[j];
            }
        }
    }
    
    bool bfs()
    {
        length++;
        queue<size_t> nextBfsQueue;
        while(!bfsQueue.empty())
        {
            size_t fromIndex = bfsQueue.front();
            bfsQueue.pop();
            
            if (wordList[fromIndex] == endWord)
                return true;
            
            for (size_t i = 0; i < wordList.size(); i++)
            {
                if (i == fromIndex)
                    continue;
                
                if (isAdjacent[fromIndex][i] && !visited[i])
                {
                    nextBfsQueue.emplace(i);
                    visited[i] = true;
                }
            }
        }
        if (!nextBfsQueue.empty())
        {
            bfsQueue.swap(nextBfsQueue);
            return bfs();
        }
        else
        {
            return false;
        }
    }
    
    void init(const string& beginWord, const string& endWord, vector<string>& wordList)
    {
        length = 1;
        this->endWord = endWord;
        dictionary = unordered_set<string>(wordList.begin(), wordList.end());
        this->wordList.swap(wordList);
        isAdjacent = vector<vector<bool>>(this->wordList.size(), vector<bool>(this->wordList.size(), false));
        visited.clear();
        wordIndex.clear();
        for (size_t i = 0; i < this->wordList.size(); i++)
        {
            wordIndex.emplace(this->wordList[i], i);
        }
        
        for (size_t i = 0; i < this->wordList.size(); i++)
        {
            string temp = this->wordList[i];
            for (size_t j = 0; j < this->wordList[i].length(); j++)
            {
                for (char k = 'a'; k <= 'z'; k++)
                {
                    if (k == this->wordList[i][j])
                        continue;
                    
                    temp[j] = k;
                    
                    if (dictionary.find(temp) != dictionary.end())
                    {
                        isAdjacent[wordIndex[this->wordList[i]]][wordIndex[temp]] = true;
                    }
                    
                    temp[j] = this->wordList[i][j];
                }
            }
        }
    }
    string endWord;
    unordered_set<string> dictionary;
    vector<string> wordList;
    unordered_map<string, size_t> wordIndex;
    unordered_map<size_t, bool> visited;
    vector<vector<bool>> isAdjacent;
    queue<size_t> bfsQueue;
    size_t length;
};

void Test()
{
    Solution solution;
    string beginWord, endWord;
    vector<string> wordList;
    
    beginWord = "hit";
    endWord = "cog";
    wordList = {"hot","dot","dog","lot","log","cog"};
    assert(solution.ladderLength(beginWord, endWord, wordList) == 5);

    beginWord = "hit";
    endWord = "cog";
    wordList = {"hot","dot","dog","lot","log"};
    assert(solution.ladderLength(beginWord, endWord, wordList) == 0);
    
    beginWord = "hit";
    endWord = "cog";
    wordList = {"hot","dot","tog","cog"};
    assert(solution.ladderLength(beginWord, endWord, wordList) == 0);
}
