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
    int findTilt(TreeNode *root)
    {
        return helper(root).first;
    }

private:
    pair<int, int> helper(TreeNode *root)
    {
        if (root == nullptr)
            return {0, 0};

        auto [lTiltSum, lSum] = helper(root->left);
        auto [rTiltSum, rSum] = helper(root->right);

        return {lTiltSum + rTiltSum + abs(lSum - rSum), lSum + rSum + root->val};
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};