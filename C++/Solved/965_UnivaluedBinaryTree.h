#pragma once
#include "Common.h"

class Solution
{
public:
    bool isUnivalTree(TreeNode *root)
    {
        if (!root)
            return true;

        if (u == -1)
        {
            u = root->val;
        }
        else if (u != root->val)
        {
            return false;
        }
        bool temp = isUnivalTree(root->left);
        if (!temp)
            return false;
        return isUnivalTree(root->right);
    }

private:
    int u = -1;
};
