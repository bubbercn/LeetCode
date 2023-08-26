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
    int sumNumbers(TreeNode* root)
    {
        if (root == nullptr)
            return 0;
        
        if (root->val == 0)
            return sumNumbers(root->left) + sumNumbers(root->right);
            
        return helper(root).first;
    }
private:
    pair<int, int> helper(TreeNode* root)
    {
        int depthSum = 0;
        int sum = 0;
        
        if (root->left != nullptr)
        {
            auto left = helper(root->left);
            depthSum += left.second * 10;
            sum += left.first;
        }
        
        if (root->right != nullptr)
        {
            auto right = helper(root->right);
            depthSum += right.second * 10;
            sum += right.first;
        }
        
        if (depthSum == 0)
            depthSum = 1;
        
        sum += root->val * depthSum;
        
        return {sum, depthSum};
    }
};

void Test()
{
    Solution solution;
    
    vector<int> values = {4, 9, 0, 5, 1};
    vector<unique_ptr<TreeNode>> nodes;
    for (auto i = values.begin(); i != values.end(); i++)
    {
        nodes.emplace_back(new TreeNode(*i));
    }
    nodes[0]->left = nodes[1].get();
    nodes[0]->right = nodes[2].get();
    nodes[1]->left = nodes[3].get();
    nodes[1]->right = nodes[4].get();
    
    assert(solution.sumNumbers(nodes[0].get()) == 1026);
}
