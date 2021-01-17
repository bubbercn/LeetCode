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
    int sumOfLeftLeaves(TreeNode *root)
    {
        if (root == nullptr)
            return 0;

        if (root->left == nullptr && root->right == nullptr)
            return 0;

        if (root->right && root->right->left == nullptr && root->right->right == nullptr)
            return helper(root->left);

        return helper(root->left) + helper(root->right);
    }

private:
    int helper(TreeNode *root)
    {
        if (root == nullptr)
            return 0;

        if (root->left == nullptr && root->right == nullptr)
            return root->val;

        if (root->right && root->right->left == nullptr && root->right->right == nullptr)
            return helper(root->left);

        return helper(root->left) + helper(root->right);
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
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
    EXPECT_EQ(solution.sumOfLeftLeaves(nodes[0].get()), 24);
}