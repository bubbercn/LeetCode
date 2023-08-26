#pragma once
#include "Common.h"

class Solution
{
public:
    TreeNode *pruneTree(TreeNode *root)
    {
        if (!root)
            return nullptr;
        root->left = pruneTree(root->left);
        root->right = pruneTree(root->right);
        if (root->left == nullptr && root->right == nullptr && root->val == 0)
            return nullptr;
        return root;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};
