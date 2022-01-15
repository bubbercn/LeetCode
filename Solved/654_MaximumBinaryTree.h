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
    TreeNode *constructMaximumBinaryTree(vector<int> &nums)
    {
        return helper(nums.begin(), nums.end());
    }
    private:
    TreeNode* helper(vector<int>::const_iterator begin, vector<int>::const_iterator end)
    {
        auto it = max_element(begin, end);
        TreeNode* root = new TreeNode(*it);
        if (it  != begin)
        {
            root->left = helper(begin, it);
        }
        if (++it != end)
        {
            root->right = helper(it, end);
        }
        return root;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};