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
    int maxDepth(Node *root)
    {
        if (root == nullptr)
            return 0;

        int max = 0;
        for (auto node : root->children)
        {
            max = ::max(max, maxDepth(node));
        }
        return max + 1;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};
