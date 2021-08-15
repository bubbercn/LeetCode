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
    vector<vector<int>> pathSum(TreeNode *root, int sum)
    {
        vector<vector<int>> result;
        list<list<int>> temp = helper(root, sum);
        for (auto& i : temp)
        {
            i.reverse();
            result.emplace_back(i.begin(), i.end());
        }
        return result;
    }

private:
    list<list<int>> helper(TreeNode *root, int sum)
    {
        if (root == nullptr)
            return {};

        if (root->left == nullptr && root->right == nullptr)
        {
            if (sum == root->val)
            {
                return {list<int>(1, sum)};
            }
            else
            {
                return {};
            }
        }

        list<list<int>> result;

        auto left = helper(root->left, sum - root->val);
        for (auto& i : left)
        {
            i.emplace_back(root->val);
            result.emplace_back(i);
        }

        auto right = helper(root->right, sum - root->val);
        for (auto& i : right)
        {
            i.emplace_back(root->val);
            result.emplace_back(i);
        }

        return result;
    }
};

void Test()
{
}