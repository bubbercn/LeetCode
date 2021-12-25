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
    vector<double> averageOfLevels(TreeNode *root)
    {
        vector<double> result;
        list<TreeNode*> current;
        current.emplace_back(root);
        while (!current.empty())
        {
            int sum = 0;
            list<TreeNode*> next;
            for (auto node : current)
            {
                sum += node->val;
                if (node->left)
                    next.emplace_back(node->left);
                if (node->right)
                    next.emplace_back(node->right);
            }
            result.emplace_back(static_cast<double>(sum) / current.size());
            current.swap(next);
        }
        return result;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};
