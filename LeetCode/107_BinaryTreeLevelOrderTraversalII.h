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
    vector<vector<int>> levelOrderBottom(TreeNode* root)
    {
        list<vector<int>> levels;

        if (root != nullptr)
        {
            list<TreeNode*> currentLevel;
            currentLevel.emplace_back(root);
            while (!currentLevel.empty())
            {
                list<TreeNode*> nextLevel;
                vector<int> temp;
                for (auto& node : currentLevel)
                {
                    temp.emplace_back(node->val);
                    if (node->left)
                        nextLevel.emplace_back(node->left);
                    if (node->right)
                        nextLevel.emplace_back(node->right);
                }
                levels.emplace_back(temp);
                swap(currentLevel, nextLevel);
            }
        }

        levels.reverse();
        
        return vector<vector<int>>(levels.begin(), levels.end());
    }
};

void Test()
{
    Solution solution;
    
    vector<int> values = {3, 9, 20, 15, 7};
    vector<unique_ptr<TreeNode>> nodes;
    for (auto i = values.begin(); i != values.end(); i++)
    {
        nodes.emplace_back(new TreeNode(*i));
    }
    nodes[0]->left = nodes[1].get();
    nodes[0]->right = nodes[2].get();
    nodes[2]->left = nodes[3].get();
    nodes[2]->right = nodes[4].get();
    
    solution.levelOrderBottom(nodes[0].get());
}
