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
    bool findTarget(TreeNode *root, int k)
    {
        lookup.clear();
        return helper(root, k);
    }

private:
    unordered_set<int> lookup;
    bool helper(TreeNode *root, int k)
    {
        if (lookup.count(root->val))
            return true;

        lookup.emplace(k - root->val);

        if (root->left && helper(root->left, k))
            return true;

        if (root->right && helper(root->right, k))
            return true;

        return false;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};
