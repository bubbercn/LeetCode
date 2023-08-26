#pragma once
#include "Common.h"

class Solution
{
public:
    TreeNode *searchBST(TreeNode *root, int val)
    {
        if (!root)
            return nullptr;

        if (root->val == val)
            return root;

        if (val < root->val)
            return searchBST(root->left, val);

        return searchBST(root->right, val);
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};
