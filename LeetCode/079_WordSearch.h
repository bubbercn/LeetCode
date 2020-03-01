#pragma once
#include "Common.h"

using Pos = pair<size_t, size_t>;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word)
    {
        init(board, word);
        
        parepareLookup();
        
        return findPath();
    }
    
private:
    void init(vector<vector<char>>& board, const string& word)
    {
        lookup.clear();
        pBoard = &board;
        this->word = word;
        boardSize.first = board.size();
        boardSize.second = board.empty() ? 0 : (*board.begin()).size();
    }
    
    void parepareLookup()
    {
        set<char> wordLookup;
        for (size_t i = 0; i < word.length(); i++)
        {
            wordLookup.insert(word[i]);
        }
        vector<vector<char>>& board = *pBoard;
        for (size_t i = 0; i < boardSize.first; i++)
        {
            for (size_t j = 0; j < boardSize.second; j++)
            {
                if (wordLookup.find(board[i][j]) != wordLookup.end())
                {
                    lookup[board[i][j]].insert(make_pair(i, j));
                }
            }
        }
    }
    
    bool findPath()
    {
        return pickOne(0, nullptr);
    }
    
    bool pickOne(size_t index, const Pos* prePos)
    {
        auto find_result = lookup.find(word[index]);
        
        if (find_result == lookup.end())
            return false;
        
        set<Pos>& temp = find_result->second;
        
        for (auto i = temp.begin(); i != temp.end();)
        {
            if (IsAdjecent(&(*i), prePos))
            {
                Pos curPos = *i;
                i = temp.erase(i);
                if (index + 1 != word.length())
                {
                    if (pickOne(index + 1, &curPos))
                    {
                        return true;
                    }
                    else
                    {
                        i = temp.insert(curPos).first;
                        i++;
                    }
                }
                else
                {
                    return true;
                }
            }
            else
            {
                i++;
            }
        }
        return false;
    }
    
    bool IsAdjecent(const Pos* p1, const Pos* p2)
    {
        if (p1 == nullptr || p2 ==  nullptr)
            return true;
        
        return (abs(static_cast<int>(p1->first - p2->first)) == 1 && (p1->second == p2->second)) || ((p1->first == p2->first) && abs(static_cast<int>(p1->second - p2->second)) == 1);
    }
                
    string word;
    pair<size_t, size_t> boardSize;
    vector<vector<char>>* pBoard;
    map<char, set<Pos>> lookup;
};

void Test()
{
    Solution solution;
    
    vector<vector<char>> board1 = {
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}
    };
    assert(solution.exist(board1, "ABCCED"));
    assert(solution.exist(board1, "SEE"));
    assert(!solution.exist(board1, "ABCB"));

    vector<vector<char>> board2 = {
        {'A','A','A','A'},
        {'A','A','A','A'},
        {'A','A','A','A'}
    };
    assert(!solution.exist(board2, "AAAAB"));

    vector<vector<char>> board3 = {
        {'a','b'},
        {'c','d'}
    };
    assert(!solution.exist(board3, "abcd"));
    
    vector<vector<char>> board4 = {
        {'a','a','a'},
        {'a','b','b'},
        {'a','b','b'},
        {'b','b','b'},
        {'b','b','b'},
        {'a','a','a'},
        {'b','b','b'},
        {'a','b','b'},
        {'a','a','b'},
        {'a','b','a'}
    };
    assert(!solution.exist(board4, "aabaaaabbb"));

}
