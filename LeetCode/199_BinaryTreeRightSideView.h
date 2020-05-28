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
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> result;
        list<TreeNode*> currentLevel;
        if (root != nullptr)
        {
            currentLevel.emplace_back(root);
        }
        
        while (!currentLevel.empty())
        {
            result.emplace_back((*currentLevel.rbegin())->val);
            list<TreeNode*> nextLevel;
            for (const auto& i : currentLevel)
            {
                if (i->left != nullptr)
                {
                    nextLevel.emplace_back(i->left);
                }
                if (i->right != nullptr)
                {
                    nextLevel.emplace_back(i->right);
                }
            }
            swap(currentLevel, nextLevel);
        }
        
        return result;
    }
};

void Test()
{
}
