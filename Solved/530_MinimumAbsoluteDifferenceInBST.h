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
    int getMinimumDifference(TreeNode *root)
    {
        return get<2>(helper(root));
    }

private:
    tuple<int, int, int> helper(TreeNode *root)
    {
        int min = root->val;
        int max = root->val;
        int result = numeric_limits<int>::max();
        if (root->left)
        {
            auto [leftMin, leftMax, leftResult] = helper(root->left);
            min = ::min(min, leftMin);
            max = ::max(max, leftMax);
            leftResult = ::min(leftResult, root->val - leftMax);
            result = ::min(result, leftResult);
        }
        if (root->right)
        {
            auto [rightMin, rightMax, rightResult] = helper(root->right);
            min = ::min(min, rightMin);
            max = ::max(max, rightMax);
            rightResult = ::min(rightResult, rightMin - root->val);
            result = ::min(result, rightResult);
        }
        return {min, max, result};
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<int> values = {4, 2, 6, 1, 3};
    vector<unique_ptr<TreeNode>> nodes;
    for (auto i = values.begin(); i != values.end(); i++)
    {
        nodes.emplace_back(new TreeNode(*i));
    }
    nodes[0]->left = nodes[1].get();
    nodes[0]->right = nodes[2].get();
    nodes[1]->left = nodes[3].get();
    nodes[1]->right = nodes[4].get();
    EXPECT_EQ(solution.getMinimumDifference(nodes[0].get()), 1);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> values = {1, 0, 48, 12, 49};
    vector<unique_ptr<TreeNode>> nodes;
    for (auto i = values.begin(); i != values.end(); i++)
    {
        nodes.emplace_back(new TreeNode(*i));
    }
    nodes[0]->left = nodes[1].get();
    nodes[0]->right = nodes[2].get();
    nodes[2]->left = nodes[3].get();
    nodes[2]->right = nodes[4].get();
    EXPECT_EQ(solution.getMinimumDifference(nodes[0].get()), 1);
}
