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
    int minDepth(TreeNode* root)
    {
        if (root == nullptr)
            return 0;

        int left = minDepth(root->left);
        int right = minDepth(root->right);

        if (left == 0)
            return right + 1;
        
        if (right == 0)
            return left + 1;
        
        return min(left, right) + 1;
    }
};

void Test()
{
    
}
