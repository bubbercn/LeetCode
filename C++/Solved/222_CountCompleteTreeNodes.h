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
    int countNodes(TreeNode* root)
    {
        return helper(root, -1, -1);
    }

    int helper(TreeNode* root, int leftHeight, int rightHeight)
    {
        if (!root)
            return 0;
        
        leftHeight = leftHeight == -1 ? getLeftHeight(root) : leftHeight;
        rightHeight = rightHeight == -1 ? getRightHeight(root) : rightHeight;

        if (leftHeight == rightHeight)
        {
            return pow(2, leftHeight) - 1;
        }
        else
        {
            return 1 + helper(root->left, leftHeight - 1, -1) + helper(root->right, -1, rightHeight - 1);
        }
    }

    int getLeftHeight(TreeNode *root)
    {
        int height = 0;
        while (root)
        {
            root = root->left;
            height++;
        }
        return height;
    }

    int getRightHeight(TreeNode *root)
    {
        int height = 0;
        while (root)
        {
            root = root->right;
            height++;
        }
        return height;
    }
};

void Test()
{
}