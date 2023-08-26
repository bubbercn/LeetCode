#pragma once
#include "Common.h"

//  Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BSTIterator
{
public:
    BSTIterator(TreeNode *root)
    {
        while (root != nullptr)
        {
            nodes.emplace(root);
            root = root->left;
        }
    }

    /** @return the next smallest number */
    int next()
    {
        TreeNode* temp = nodes.top();
        nodes.pop();
        int result = temp->val;
        temp = temp->right;
        while (temp != nullptr)
        {
            nodes.emplace(temp);
            temp = temp->left;
        }
        return result;
    }

    /** @return whether we have a next smallest number */
    bool hasNext()
    {
        return !nodes.empty();
    }

private:
    stack<TreeNode*> nodes;
};

void Test()
{
}