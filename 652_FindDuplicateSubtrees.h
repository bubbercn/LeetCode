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
    vector<TreeNode *> findDuplicateSubtrees(TreeNode *root)
    {
        lookup.clear();
        duplicatedInorderTraversals.clear();
        inorderTraversal(root);
        vector<TreeNode *> result;
        for (const auto &inorderTraversal : duplicatedInorderTraversals)
        {
            result.emplace_back(lookup[inorderTraversal]);
        }
        return result;
    }

private:
    unordered_map<string, TreeNode *> lookup;
    unordered_set<string> duplicatedInorderTraversals;
    string inorderTraversal(TreeNode *root)
    {
        if (!root)
            return {};

        string result = inorderTraversal(root->left);
        if (result.empty())
        {
            result = to_string(root->val);
        }
        else
        {
            result += "L" + to_string(root->val);
        }
        string temp = inorderTraversal(root->right);
        if (!temp.empty())
        {
            result += "R" + temp;
        }

        if (!lookup.emplace(result, root).second)
            duplicatedInorderTraversals.emplace(result);

        return result;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};
