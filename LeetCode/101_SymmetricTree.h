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

class Solution
{
public:
    bool isSymmetric(TreeNode* root)
    {
        if (root == nullptr)
            return true;
        return isReverse(root->left, root->right);
    }

private:
    bool isReverse(TreeNode* node1, TreeNode* node2)
    {
        if (node1 == nullptr)
        {
            return node2 == nullptr;
        }

        if (node2 == nullptr)
        {
            return node1 == nullptr;
        }

        return node1->val == node2->val && isReverse(node1->left, node2->right) && isReverse(node1->right, node2->left);
    }
};

void Test()
{
    
}
