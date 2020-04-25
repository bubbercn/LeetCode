#pragma once
#include "Common.h"

class Solution
{
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList)
    {
        init(beginWord, endWord, wordList);
        
        if (dictionary.find(endWord) == dictionary.end())
            return {};
        
        deque<size_t> bfsQueue = firstStep(beginWord);
        
        vector<deque<size_t>> levels = bfs(bfsQueue);
        
        if (levels.empty())
            return {};
        
        postProcess(bfsQueue, levels);
        
        return generateResult(beginWord, levels);
    }
private:
    deque<size_t> firstStep(const string& beginWord)
    {
        deque<size_t> bfsQueue;
        
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
                    bfsQueue.emplace_back(wordIndex[temp]);
                    visited[wordIndex[temp]] = true;
                }
                
                temp[j] = beginWord[j];
            }
        }
        
        return bfsQueue;
    }
    
    vector<deque<size_t>> bfs(deque<size_t> bfsQueue)
    {
        bool foundEndWord = false;
        deque<size_t> nextBfsQueue;
        while(!bfsQueue.empty())
        {
            size_t fromIndex = bfsQueue.front();
            bfsQueue.pop_front();
            
            if (wordList[fromIndex] == endWord)
            {
                nextBfsQueue.clear();
                foundEndWord = true;
                nextBfsQueue.emplace_back(fromIndex);
                break;
            }
            else
            {
                if (foundEndWord)
                    continue;
                
                for (size_t i = 0; i < wordList.size(); i++)
                {
                    if (i == fromIndex)
                        continue;
                    
                    if (isAdjacent[fromIndex][i] && !visited[i])
                    {
                        nextBfsQueue.emplace_back(i);
                        visited[i] = true;
                    }
                }
            }
        }
        if (!nextBfsQueue.empty())
        {
            if (foundEndWord)
            {
                return {nextBfsQueue};
            }
            
            vector<deque<size_t>> result = bfs(nextBfsQueue);
            
            postProcess(nextBfsQueue, result);
            return result;
        }
        else
        {
            return {};
        }
    }
    
    void init(const string& beginWord, const string& endWord, vector<string>& wordList)
    {
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
    
    vector<vector<string>> generateResult(const string& beginWord,vector<deque<size_t>>& levels)
    {
        vector<vector<string>> result;
        result.push_back({beginWord});
        
        for (int i = static_cast<int>(levels.size() - 1); i >= 0; i--)
        {
            vector<vector<string>> nextResult;
            for (auto& j : result)
            {
                for (auto k : levels[i])
                {
                    vector<string> temp = j;
                    if (i == levels.size() - 1 || isAdjacent[wordIndex[*j.rbegin()]][k])
                    {
                        temp.emplace_back(wordList[k]);
                        nextResult.emplace_back(temp);
                    }
                }
            }
            result.swap(nextResult);
        }
        
        return result;
    }
    
    bool contains(const deque<size_t>& queue, size_t element)
    {
        for (auto i : queue)
        {
            if (i == element)
                return true;
        }
        return false;
    }
    
    void postProcess(deque<size_t>& queue, vector<deque<size_t>>& result)
    {
        if (result.empty())
        {
            ;
        }
        else if (result.size() == 1 && (*result.begin()).size() == 1 && contains(queue, *(*result.begin()).begin()))
        {
            ;
        }
        else
        {
            removeUnconnected(queue, result);
            result.emplace_back(queue);
        }
    }
    
    void removeUnconnected(deque<size_t>& queue, const vector<deque<size_t>>& result)
    {
        const deque<size_t>& lastQueue = *result.rbegin();
        auto i = queue.begin();
        while (i != queue.end())
        {
            bool isConnected = false;
            for (auto j : lastQueue)
            {
                if (isAdjacent[*i][j])
                {
                    isConnected = true;
                    break;
                }
            }
            if (isConnected)
            {
                i++;
            }
            else
            {
                i = queue.erase(i);
            }
        }
    }
    
    string endWord;
    unordered_set<string> dictionary;
    vector<string> wordList;
    unordered_map<string, size_t> wordIndex;
    unordered_map<size_t, bool> visited;
    vector<vector<bool>> isAdjacent;
};

void Test()
{
    Solution solution;
    string beginWord, endWord;
    vector<string> wordList;
    
//    beginWord = "hit";
//    endWord = "cog";
//    wordList = {"hot","dot","dog","lot","log","cog"};
//    assert(solution.findLadders(beginWord, endWord, wordList).size() == 2);
//
//    beginWord = "hit";
//    endWord = "cog";
//    wordList = {"hot","dot","dog","lot","log"};
//    assert(solution.findLadders(beginWord, endWord, wordList).empty());
//
//    beginWord = "hit";
//    endWord = "cog";
//    wordList = {"hot","dot","tog","cog"};
//    assert(solution.findLadders(beginWord, endWord, wordList).empty());
    
    beginWord = "a";
    endWord = "c";
    wordList = {"a","b","c"};
    assert(solution.findLadders(beginWord, endWord, wordList).size() == 1);

}
