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
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (!root || !p || !q)
            return nullptr;

        while (true)
        {
            if (root == p || root == q)
            {
                break;
            }
            else if ((p->val < root->val && q->val > root->val) || (q->val < root->val && p->val > root->val))
            {
                break;
            }
            else if (p->val < root->val)
            {
                root = root->left;
            }
            else
            {
                root = root->right;
            }
        }
        return root;
    }
};

void Test()
{
}