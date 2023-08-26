#pragma once
#include "Common.h"

class Solution
{
public:
    TreeNode *insertIntoMaxTree(TreeNode *root, int val)
    {
        if (root == nullptr || val > root->val)
            return new TreeNode(val, root, nullptr);
        root->right = insertIntoMaxTree(root->right, val);
        return root;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};
