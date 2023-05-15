#pragma once
#include "Common.h"

class Solution
{
public:
    int rangeSumBST(TreeNode *root, int low, int high)
    {
        if (!root)
            return 0;
        
        if (root->val < low)
            return rangeSumBST(root->right, low, high);
        
        if (root->val > high)
            return rangeSumBST(root->left, low, high);

        return rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high) + root->val;
    }
};


