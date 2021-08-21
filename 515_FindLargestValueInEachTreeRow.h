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
    vector<int> largestValues(TreeNode *root)
    {
        vector<int> result;
        queue<TreeNode*> current;
        if (root)
        {
            current.emplace(root);
        }
        while (!current.empty())
        {
            int max = numeric_limits<int>::min();
            queue<TreeNode*> next;
            while (!current.empty())
            {
                TreeNode* node = current.front();
                max = ::max(max, node->val);
                if (node->left)
                    next.emplace(node->left);
                if (node->right)
                    next.emplace(node->right);
                current.pop();
            }
            result.emplace_back(max);
            swap(current, next);
        }
        return result;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<int> values = {1, 3, 2, 5, 3, 9};
    vector<unique_ptr<TreeNode>> nodes;
    for (auto i = values.begin(); i != values.end(); i++)
    {
        nodes.emplace_back(new TreeNode(*i));
    }
    nodes[0]->left = nodes[1].get();
    nodes[0]->right = nodes[2].get();
    nodes[1]->left = nodes[3].get();
    nodes[1]->right = nodes[4].get();
    nodes[2]->right = nodes[5].get();
    vector<int> output = {1, 3, 9};
    EXPECT_EQ(solution.largestValues(nodes[0].get()), output);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> values = {1, 2, 3};
    vector<unique_ptr<TreeNode>> nodes;
    for (auto i = values.begin(); i != values.end(); i++)
    {
        nodes.emplace_back(new TreeNode(*i));
    }
    nodes[0]->left = nodes[1].get();
    nodes[0]->right = nodes[2].get();
    vector<int> output = {1, 3};
    EXPECT_EQ(solution.largestValues(nodes[0].get()), output);
}

TEST_F(LeetCodeTest, Example3)
{
    vector<int> values = {1};
    vector<unique_ptr<TreeNode>> nodes;
    for (auto i = values.begin(); i != values.end(); i++)
    {
        nodes.emplace_back(new TreeNode(*i));
    }
    vector<int> output = {1};
    EXPECT_EQ(solution.largestValues(nodes[0].get()), output);
}

TEST_F(LeetCodeTest, Example4)
{
    vector<int> values = {1, 2};
    vector<unique_ptr<TreeNode>> nodes;
    for (auto i = values.begin(); i != values.end(); i++)
    {
        nodes.emplace_back(new TreeNode(*i));
    }
    nodes[0]->right = nodes[1].get();
    vector<int> output = {1, 2};
    EXPECT_EQ(solution.largestValues(nodes[0].get()), output);
}

TEST_F(LeetCodeTest, Example5)
{
    vector<int> output = {};
    EXPECT_EQ(solution.largestValues(nullptr), output);
}