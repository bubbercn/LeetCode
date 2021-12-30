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
        deque<pair<TreeNode *, long>> curLevel;
        root->val = 0;
        curLevel.emplace_back(root, 1);
        int result = 0;
        while (!curLevel.empty())
        {
            int sum = 0;
            deque<pair<TreeNode *, long>> nextLevel;
            for (auto node : curLevel)
            {
                if (node.first == nullptr)
                {
                    nextLevel.emplace_back(nullptr, node.second * 2);
                }
                else
                {
                    nextLevel.emplace_back(node.first->left, 1);
                    nextLevel.emplace_back(node.first->right, 1);
                }   
                sum += node.second;
            }
            result = max(result, sum);
            while (!nextLevel.empty() && nextLevel.front().first == nullptr)
                nextLevel.pop_front();
            while (!nextLevel.empty() && nextLevel.back().first == nullptr)
                nextLevel.pop_back();
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