#pragma once
#include "Common.h"

class Solution
{
public:
    TreeNode *insertIntoBST(TreeNode *root, int val)
    {
        return helper(root, val);
    }

private:
    TreeNode *helper(TreeNode *root, int val)
    {
        if (!root)
        {
            return new TreeNode(val);
        }

        if (val < root->val)
        {
            if (root->left)
            {
                helper(root->left, val);
            }
            else
            {
                root->left = new TreeNode(val);
            }
        }
        else
        {
            if (root->right)
            {
                helper(root->right, val);
            }
            else
            {
                root->right = new TreeNode(val);
            }
        }

        return root;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};