#pragma once
#include "Common.h"

class Solution
{
public:
    TreeNode *increasingBST(TreeNode *root)
    {
        helper(root);
        return result;
    }

private:
    TreeNode *next = nullptr;
    TreeNode *result = nullptr;
    void helper(TreeNode *root)
    {
        if (root == nullptr)
            return;

        helper(root->left);
        if (!next)
        {
            result = new TreeNode(root->val);
            next = result;
        }
        else
        {
            next->right = new TreeNode(root->val);
            next = next->right;
        }
        helper(root->right);
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};