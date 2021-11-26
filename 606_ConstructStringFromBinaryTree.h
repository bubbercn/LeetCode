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
    string tree2str(TreeNode *root)
    {
        string result = to_string(root->val);
        if (root->left)
        {
            result += "(";
            result += tree2str(root->left);
            result += ")";
        }
        else if (root->right)
        {
            result += "()";
        }
        if (root->right)
        {
            result += "(";
            result += tree2str(root->right);
            result += ")";
        }
        return result;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};
