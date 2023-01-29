#pragma once
#include "Common.h"

class Solution
{
public:
    bool leafSimilar(TreeNode *root1, TreeNode *root2)
    {
        TreeIterator it1(root1);
        TreeIterator it2(root2);
        TreeNode *leaf1 = nullptr;
        TreeNode *leaf2 = nullptr;
        while (true)
        {
            leaf1 = it1.getNextLeaf();
            leaf2 = it2.getNextLeaf();
            if (leaf1 && leaf2)
            {
                if (leaf1->val != leaf2->val)
                    return false;
            }
            else
            {
                return leaf1 == leaf2;
            }
        }
        return false;
    }

private:
    class TreeIterator
    {
    public:
        TreeIterator(TreeNode *root)
        {
            nodes.emplace(root);
        }
        TreeNode *getNextLeaf()
        {
            if (nodes.empty())
                return nullptr;

            TreeNode *node = nodes.top();
            while (node->left || node->right)
            {
                nodes.pop();
                if (node->right)
                    nodes.emplace(node->right);
                if (node->left)
                    nodes.emplace(node->left);
                node = nodes.top();
            }
            nodes.pop();
            return node;
        }

    private:
        stack<TreeNode *> nodes;
    };
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<int> values1 = {1, 2, 3};
    vector<unique_ptr<TreeNode>> nodes1;
    for (auto value : values1)
    {
        nodes1.emplace_back(new TreeNode(value));
    }
    nodes1[0]->left = nodes1[1].get();
    nodes1[0]->right = nodes1[2].get();

    vector<int> values2 = {1, 3, 2};
    vector<unique_ptr<TreeNode>> nodes2;
    for (auto value : values2)
    {
        nodes2.emplace_back(new TreeNode(value));
    }
    nodes2[0]->left = nodes2[1].get();
    nodes2[0]->right = nodes2[2].get();

    EXPECT_EQ(solution.leafSimilar(nodes1[0].get(), nodes2[0].get()), false);
}