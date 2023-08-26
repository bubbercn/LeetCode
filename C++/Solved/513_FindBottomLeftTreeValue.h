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
    int findBottomLeftValue(TreeNode *root)
    {
        return helper(root).first;
    }

private:
    pair<int, int> helper(TreeNode *node)
    {
        if (node == nullptr)
        {
            return {0, 0};
        }
        auto [leftResult, leftDepth] = helper(node->left);
        auto [rightResult, rightDepth] = helper(node->right);
        if (leftDepth == 0 && rightDepth == 0)
        {
            return {node->val, 1};
        }
        else if (leftDepth >= rightDepth)
        {
            return {leftResult, leftDepth + 1};
        }
        else
        {
            return {rightResult, rightDepth + 1};
        }
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<int> values = {2, 1, 3};
    vector<unique_ptr<TreeNode>> nodes;
    for (auto i = values.begin(); i != values.end(); i++)
    {
        nodes.emplace_back(new TreeNode(*i));
    }
    nodes[0]->left = nodes[1].get();
    nodes[0]->right = nodes[2].get();
    EXPECT_EQ(solution.findBottomLeftValue(nodes[0].get()), 1);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> values = {1, 2, 3, 4, 5, 6, 7};
    vector<unique_ptr<TreeNode>> nodes;
    for (auto i = values.begin(); i != values.end(); i++)
    {
        nodes.emplace_back(new TreeNode(*i));
    }
    nodes[0]->left = nodes[1].get();
    nodes[0]->right = nodes[2].get();
    nodes[1]->left = nodes[3].get();
    nodes[2]->left = nodes[4].get();
    nodes[2]->right = nodes[5].get();
    nodes[4]->left = nodes[6].get();
    EXPECT_EQ(solution.findBottomLeftValue(nodes[0].get()), 7);
}