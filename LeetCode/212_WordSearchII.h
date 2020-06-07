#pragma once
#include "Common.h"

//struct pair_hash
//{
//    template<class T1, class T2>
//    std::size_t operator() (const std::pair<T1, T2>& p) const
//    {
//        auto h1 = std::hash<T1>{}(p.first);
//        auto h2 = std::hash<T2>{}(p.second);
//        return h1 ^ h2;
//    }
//};

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
        visited.emplace_back(i, j);
        helper(board, visited, indexRoot, result);
        return result;
    }
    
    void helper(const vector<vector<char>>& board, list<pair<int, int>>& visited, IndexNode& indexNode, vector<string>& result)
    {
        auto pos = *visited.rbegin();
        auto found = indexNode.childIndexNodes.find(board[pos.first][pos.second]);
        if (found == indexNode.childIndexNodes.end())
        {
            visited.pop_back();
            return;
        }

        if (found->second->hasWord)
        {
            string word(' ', visited.size());
            int index = 0;
            for (const auto& pos : visited)
            {
                word[index++] = board[pos.first][pos.second];
            }
            result.emplace_back(word);
            
            // to do: cut off index
            found->second->hasWord = false;
        }
        
        
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
