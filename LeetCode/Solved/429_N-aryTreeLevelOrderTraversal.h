#pragma once
#include "Common.h"

// Definition for a Node.
class Node
{
public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val)
    {
        val = _val;
    }

    Node(int _val, vector<Node *> _children)
    {
        val = _val;
        children = _children;
    }
};

class Solution
{
public:
    vector<vector<int> > levelOrder(Node *root)
    {
        if (root == nullptr)
            return {};

        vector<vector<int>> result;
        list<Node*> nextLevel;
        nextLevel.emplace_back(root);
        while (!nextLevel.empty())
        {
            list<Node*> currentLevel;
            currentLevel.swap(nextLevel);
            vector<int> temp(currentLevel.size(), 0);
            int index = 0;
            for (auto node : currentLevel)
            {
                temp[index++] = node->val;
                for (auto child : node->children)
                {
                    nextLevel.emplace_back(child);
                }
            }
            result.emplace_back(temp);
        }

        return result;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};