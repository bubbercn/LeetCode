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
    bool isSameTree(TreeNode* p, TreeNode* q)
    {
        if (p == nullptr)
            return q == nullptr;
        
        if (q == nullptr)
            return p == nullptr;
        
        return p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

void Test()
{
    
}
