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
    int widthOfBinaryTree(TreeNode *root)
    {
        int result = 0;
        list<TreeNode*> curLevel;
        root->val = 0;
        curLevel.emplace_back(root);
        while (!curLevel.empty())
        {
            int min = numeric_limits<int>::min();
            int max = numeric_limits<int>::max();
            list<TreeNode*> nextLevel;
            for (auto node : curLevel)
            {
                min = ::min(min, node->val);
                max = ::max(max, node->val);
                if (node->left)
                {
                    node->left->val = node->val * 2;
                    nextLevel.emplace_back(node->left);
                }
                if (node->right)
                {
                    node->right->val = node->val * 2 + 1;
                    nextLevel.emplace_back(node->right);
                }
            }
            int width = max - min + 1;
            result = ::max(result, width);
            curLevel.swap(nextLevel);
        }
        return result;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};