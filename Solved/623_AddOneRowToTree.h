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
    TreeNode *addOneRow(TreeNode *root, int val, int depth)
    {
        if (depth == 1)
        {
            TreeNode* node = new TreeNode(val, root, nullptr);
            return node;
        }

        list<TreeNode*> currentLayer = {root};
        while (!currentLayer.empty())
        {           
            if (depth == 2)
            {
                for (auto node : currentLayer)
                {
                    node->left = new TreeNode(val, node->left, nullptr);
                    node->right = new TreeNode(val, nullptr, node->right);
                }
                break;
            }
            else
            {
                list<TreeNode*> nextLayer;
                for (auto node : currentLayer)
                {
                    if (node->left)
                    {
                        nextLayer.emplace_back(node->left);
                    }
                    if (node->right)
                    {
                        nextLayer.emplace_back(node->right);
                    }
                }
                currentLayer.swap(nextLayer);
            }
            depth--;
        }

        return root;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};
