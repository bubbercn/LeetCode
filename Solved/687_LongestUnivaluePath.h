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
    int longestUnivaluePath(TreeNode *root)
    {
        return helper(root).first;
    }

private:
    pair<int, int> helper(TreeNode *root)
    {
        if (root == nullptr)
            return {0, 0};

        auto [lMax, lDepth] = helper(root->left);
        auto [rMax, rDepth] = helper(root->right);
        int result = 0, depth = 0;
        if (root->left && root->val == root->left->val)
        {
            result = lDepth + 1;
            depth = max(depth, result);
        }
        if (root->right && root->val == root->right->val)
        {
            result += rDepth + 1;
            depth = max(depth, rDepth + 1);
        }
        result = max(result, lMax);
        result = max(result, rMax);
        return {result, depth};
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};
