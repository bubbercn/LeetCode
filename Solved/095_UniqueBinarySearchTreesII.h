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

class Solution {
public:
    vector<TreeNode*> generateTrees(int n) 
    {
        return helper(1, n);
    }

private:
    vector<TreeNode*> helper(int min, int max)
    {
        auto it = lookUp.find(make_pair(min, max));
        if (it != lookUp.end())
        {
            return it->second;
        }

        vector<TreeNode*> result;
        if (min == max)
        {
            result.emplace_back(new TreeNode(min));
            lookUp.emplace(make_pair(min, max), result);
            return result;
        }
        
        for (int i = min; i <= max; i++)
        {
            vector<TreeNode*> left = (i == min ? vector<TreeNode*>({nullptr}) : helper(min, i - 1));
            vector<TreeNode*> right = (i == max ? vector<TreeNode*>({nullptr}) : helper(i + 1, max));
            for (auto& leftIt : left)
            {
                for (auto& rightIt : right)
                {
                    TreeNode* root = new TreeNode(i);
                    root->left = leftIt;
                    root->right = rightIt;
                    result.emplace_back(root);
                }
            }
        }

        lookUp.emplace(make_pair(min, max), result);
        return result;
    }
    map<pair<int, int>, vector<TreeNode*>> lookUp;
};

void Test()
{
    Solution solution;
    auto i = solution.generateTrees(3);    
}