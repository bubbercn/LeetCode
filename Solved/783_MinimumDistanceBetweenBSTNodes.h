#pragma once
#include "Common.h"

class Solution
{
public:
    int minDiffInBST(TreeNode *root)
    {
        prev = -1;
        return helper(root);
    }

private:
    int prev = -1;
    int helper(TreeNode *root)
    {
        if (root == nullptr)
            return numeric_limits<int>::max();
        int min = helper(root->left);
        if (prev != -1)
        {
            min = ::min(min, root->val - prev);
        }
        prev = root->val;
        return ::min(min, helper(root->right));
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};