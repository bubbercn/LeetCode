#pragma once
#include "Common.h"

class Solution
{
public:
    TreeNode *subtreeWithAllDeepest(TreeNode *root)
    {
        return helper(root).first;
    }

private:
    pair<TreeNode *, int> helper(TreeNode *root)
    {
        if (!root)
            return {nullptr, 0};
        
        auto [leftNode, leftDepth] = helper(root->left);
        auto [rightNode, rightDepth] = helper(root->right);
        if (leftDepth == rightDepth)
            return {root, leftDepth + 1};
        
        return leftDepth > rightDepth ? make_pair(leftNode, leftDepth + 1) : make_pair(rightNode, rightDepth + 1);
    }
};
