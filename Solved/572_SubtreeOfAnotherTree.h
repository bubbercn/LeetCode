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
    bool isSubtree(TreeNode *root, TreeNode *subRoot)
    {
        if (isEqual(root, subRoot))
            return true;

        if (root == nullptr)
            return false;

        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }

private:
    bool isEqual(TreeNode *root1, TreeNode *root2)
    {
        if (root1 == nullptr && root2 == nullptr)
            return true;

        if (root1 == nullptr || root2 == nullptr)
            return false;

        if (root1->val != root2->val)
            return false;

        return isEqual(root1->left, root2->left) && isEqual(root1->right, root2->right);
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};
