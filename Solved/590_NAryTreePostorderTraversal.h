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
    vector<int> postorder(Node *root)
    {
        vector<int> result;
        helper(root, result);
        return result;
    }

private:
    void helper(Node *root, vector<int> &result)
    {
        if (root == nullptr)
            return;

        for (auto child : root->children)
        {
            helper(child, result);
        }

        result.emplace_back(root->val);
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};