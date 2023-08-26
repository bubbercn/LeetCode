#pragma once
#include "Common.h"

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    int pathSum(TreeNode *root, int sum)
    {
        int result = 0;
        dfs(root, sum, result);
        return result;
    }

private:
    list<int> dfs(TreeNode *root, int sum, int &result)
    {
        if (!root)
            return {};

        list<int> left = dfs(root->left, sum, result);
        list<int> right = dfs(root->right, sum, result);
        list<int> output;
        for (auto i : left)
        {
            output.emplace_back(i + root->val);
            if (i + root->val == sum)
                result++;
        }
        for (auto i : right)
        {
            output.emplace_back(i + root->val);
            if (i + root->val == sum)
                result++;
        }
        output.emplace_back(root->val);
        if (root->val == sum)
            result++;
        return output;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<int> values = {10, 5, -3, 3, 2, 11, 3, -2, 1};
    vector<unique_ptr<TreeNode> > nodes;
    for (auto i = values.begin(); i != values.end(); i++)
    {
        nodes.emplace_back(new TreeNode(*i));
    }
    nodes[0]->left = nodes[1].get();
    nodes[0]->right = nodes[2].get();
    nodes[1]->left = nodes[3].get();
    nodes[1]->right = nodes[4].get();
    nodes[2]->right = nodes[5].get();
    nodes[3]->left = nodes[6].get();
    nodes[3]->right = nodes[7].get();
    nodes[4]->right = nodes[8].get();
    EXPECT_EQ(solution.pathSum(nodes[0].get(), 8), 3);
}