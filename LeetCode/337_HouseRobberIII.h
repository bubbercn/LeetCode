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
    int rob(TreeNode *root)
    {
        dp.clear();
        return helper(root, true);
    }

private:
    int helper(TreeNode *root, bool allowRubbingRoot)
    {
        if (root == nullptr)
            return 0;

        auto it = dp.find(root);
        if (it == dp.end())
        {
            int result1 = 0;
            int result2 = 0;
            result2 = helper(root->left, true) + helper(root->right, true);
            result1 = root->val + helper(root->left, false) + helper(root->right, false);

            it = dp.emplace(root, make_pair(result1, result2)).first;
        }

        return allowRubbingRoot ? max(it->second.first, it->second.second) : it->second.second;
    }
    unordered_map<TreeNode *, pair<int, int>> dp;
};

class LeetCodeTest : public testing::Test
{
public:
    static Solution solution;
};