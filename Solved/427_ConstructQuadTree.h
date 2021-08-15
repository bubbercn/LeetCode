#pragma once
#include "Common.h"

// Definition for a QuadTree node.
class Node
{
public:
    bool val;
    bool isLeaf;
    Node *topLeft;
    Node *topRight;
    Node *bottomLeft;
    Node *bottomRight;

    Node()
    {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf)
    {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf, Node *_topLeft, Node *_topRight, Node *_bottomLeft, Node *_bottomRight)
    {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};

class Solution
{
public:
    Node *construct(vector<vector<int> > &grid)
    {
        return helper(grid, 0, 0, grid.size());
    }
private:
    Node* helper(const vector<vector<int>>& grid, int top, int left, int length)
    {
        if (length == 0)
            return nullptr;
        
        Node* root = new Node();
        int checkResult = check(grid, top, left, length);
        if (checkResult == 1)
        {
            root->isLeaf = true;
            root->val = 1;
        }
        else if (checkResult == 0)
        {
            root->isLeaf = true;
            root->val = 0;
        }
        else
        {
            root->topLeft = helper(grid, top, left, length / 2);
            root->topRight = helper(grid, top, left + length / 2, length / 2);
            root->bottomLeft = helper(grid, top + length / 2, left, length / 2);
            root->bottomRight = helper(grid, top + length / 2, left + length / 2, length / 2);
        }
        return root;
    }

    int check(const vector<vector<int>>& grid, int top, int left, int length)
    {
        assert(length >= 1);
        int result = -1;
        for (int i = 0; i < length; i++)
        {
            for (int j = 0; j < length; j++)
            {
                if (result == -1)
                {
                    result = grid[top + i][left + j];
                }
                else
                {
                    if (result != grid[top + i][left + j])
                        return -1;
                }
            }
        }
        return result;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};
