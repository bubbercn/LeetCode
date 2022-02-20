#pragma once
#include "Common.h"

//  Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    int findSecondMinimumValue(TreeNode *root)
    {
        if (root == nullptr)
            return -1;

        if (root->left == nullptr)
            return -1;

        int leftResult = root->val == root->left->val ? findSecondMinimumValue(root->left) : root->left->val;
        int rightResult = root->val == root->right->val ? findSecondMinimumValue(root->right) : root->right->val;

        if (leftResult == -1)
        {
            if (rightResult == -1)
                return -1;
            return rightResult;
        }
        else
        {
            if (rightResult == -1)
                return leftResult;
            return min(leftResult, rightResult);
        }
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};