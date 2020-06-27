#pragma once
#include "Common.h"

struct pair_hash
{
    template<class T1, class T2>
    std::size_t operator() (const std::pair<T1, T2>& p) const
    {
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);
        return h1 ^ h2;
    }
};

class Solution
{
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words)
    {
        buildIndex(words);
        return scanBoard(board);
    }
private:
    struct IndexNode;
    using Index = unordered_map<char, unique_ptr<IndexNode>>;
    struct IndexNode
    {
        IndexNode(IndexNode* parent = nullptr) : parent(parent)
        {
            
        }
        bool hasWord = false;
        Index childIndexNodes;
        IndexNode* parent = nullptr;
    };
    IndexNode indexRoot;
    
    void buildIndex(vector<string>& words)
    {
        for (const auto& word: words)
        {
            addWord(word);
        }
    }
    
    void addWord(const string& word)
    {
        IndexNode* curIndexNode = &indexRoot;
        for (int i = 0; i < word.length(); i++)
        {
            auto it = curIndexNode->childIndexNodes.emplace(word[i], new IndexNode(curIndexNode));
            curIndexNode = it.first->second.get();
            if (i == word.length() - 1)
            {
                it.first->second->hasWord = true;
            }
        }
    }
    
    vector<string> scanBoard(const vector<vector<char>>& board)
    {
        vector<string> result;
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                auto temp = dfs(board, i, j);
                result.insert(result.end(), temp.begin(), temp.end());
            }
        }
        return result;
    }
    
    vector<string> dfs(const vector<vector<char>>& board, int i, int j)
    {
        vector<string> result;
        list<pair<int, int>> visited;
        unordered_set<pair<int, int>, pair_hash> visitedLookup;
        visited.emplace_back(i, j);
        visitedLookup.emplace(i, j);
        helper(board, visited, visitedLookup, indexRoot, result);
        return result;
    }
    
    bool helper(const vector<vector<char>>& board, list<pair<int, int>>& visited, unordered_set<pair<int, int>, pair_hash>& visitedLookup, IndexNode& indexNode, vector<string>& result)
    {
        auto pos = *visited.rbegin();
        auto found = indexNode.childIndexNodes.find(board[pos.first][pos.second]);
        if (found == indexNode.childIndexNodes.end())
        {
            visitedLookup.erase(pos);
            visited.pop_back();
            return false;
        }
        
        if (found->second->hasWord)
        {
            ostringstream word;
            for (const auto& pos : visited)
            {
                word << board[pos.first][pos.second];
            }
            result.emplace_back(word.str());
            
            // to do: cut off index
            found->second->hasWord = false;
            if (found->second->childIndexNodes.empty())
            {
                indexNode.childIndexNodes.erase(found);
                visitedLookup.erase(pos);
                visited.pop_back();
                return true;
            }
        }
        
        list<pair<int, int>> nextPoses = getNextPoses(pos, board, visitedLookup);
        for (const auto& nextPos : nextPoses)
        {
            visited.emplace_back(nextPos);
            visitedLookup.emplace(nextPos);
            if (helper(board, visited, visitedLookup, *found->second, result))
            {
                if (found->second->childIndexNodes.empty())
                {
                    indexNode.childIndexNodes.erase(found);
                    visitedLookup.erase(pos);
                    visited.pop_back();
                    return true;
                }
            }
        }
        
        visitedLookup.erase(pos);
        visited.pop_back();
        return false;
    }
    
    list<pair<int, int>> getNextPoses(const pair<int, int>& curPos, const vector<vector<char>>& board, unordered_set<pair<int, int>, pair_hash>& visitedLookup)
    {
        list<pair<int, int>> result;
        if (curPos.first - 1 >= 0 && visitedLookup.find(make_pair(curPos.first - 1, curPos.second)) == visitedLookup.end())
        {
            result.emplace_back(curPos.first - 1, curPos.second);
        }
        if (curPos.first + 1 < board.size() && visitedLookup.find(make_pair(curPos.first + 1, curPos.second)) == visitedLookup.end())
        {
            result.emplace_back(curPos.first + 1, curPos.second);
        }
        if (curPos.second - 1 >= 0 && visitedLookup.find(make_pair(curPos.first, curPos.second - 1)) == visitedLookup.end())
        {
            result.emplace_back(curPos.first, curPos.second - 1);
        }
        if (curPos.second + 1 < board[0].size() && visitedLookup.find(make_pair(curPos.first, curPos.second + 1)) == visitedLookup.end())
        {
            result.emplace_back(curPos.first, curPos.second + 1);
        }
        return result;
    }
    
};

void Test()
{
    Solution solution;
    vector<string> words = {"oath","pea","eat","rain"};
    vector<vector<char>> board = {
        {'o','a','a','n'},
        {'e','t','a','e'},
        {'i','h','k','r'},
        {'i','f','l','v'}
    };
    
    solution.findWords(board, words);
}
