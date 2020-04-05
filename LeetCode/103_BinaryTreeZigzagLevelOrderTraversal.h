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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
    {
        vector<vector<int>> result;

        if (root != nullptr)
        {
            list<TreeNode*> currentLevel;
            currentLevel.emplace_back(root);
            while (!currentLevel.empty())
            {
                list<TreeNode*> nextLevel;
                list<int> temp;
                for (auto& node : currentLevel)
                {
                    temp.emplace_back(node->val);
                    if (node->left)
                        nextLevel.emplace_back(node->left);
                    if (node->right)
                        nextLevel.emplace_back(node->right);
                }
                if (result.size() % 2)
                {
                    temp.reverse();
                }
                result.emplace_back(temp.begin(), temp.end());
                swap(currentLevel, nextLevel);
            }   
        }

        return result;
    }
};

void Test()
{

}