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
    TreeNode *convertBST(TreeNode *root)
    {
        int sum = 0;
        helper(root, sum);
        return root;
    }

private:
    void helper(TreeNode *node, int &sum)
    {
        if (!node)
            return;
        helper(node->right, sum);
        sum += node->val;
        node->val = sum;
        helper(node->left, sum);
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<int> values = {4,1,6,0,2,5,7,3,8};
    vector<unique_ptr<TreeNode>> nodes;
    for (auto i = values.begin(); i != values.end(); i++)
    {
        nodes.emplace_back(new TreeNode(*i));
    }
    nodes[0]->left = nodes[1].get();
    nodes[0]->right = nodes[2].get();
    nodes[1]->left = nodes[3].get();
    nodes[1]->right = nodes[4].get();
    nodes[2]->left = nodes[5].get();
    nodes[2]->right = nodes[6].get();
    nodes[4]->right = nodes[7].get();
    nodes[6]->right = nodes[8].get();
    solution.convertBST(nodes[0].get());
}