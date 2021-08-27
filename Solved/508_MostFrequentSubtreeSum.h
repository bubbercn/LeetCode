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
    vector<int> findFrequentTreeSum(TreeNode *root)
    {
        lookup.clear();
        max = 0;
        helper(root);
        vector<int> result;
        for (const auto& [sum, count] : lookup)
        {
            if (count == max)
            {
                result.emplace_back(sum);
            }
        }
        return result;
    }

private:
    int helper(TreeNode *node)
    {
        if (node == nullptr)
            return 0;
    
        int sum = helper(node->left) + helper(node->right) + node->val;
        lookup[sum]++;
        max = ::max(max, lookup[sum]);
        return sum;
    }
    unordered_map<int, int> lookup;
    int max;
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<int> values = {5, 2, -3};
    vector<unique_ptr<TreeNode>> nodes;
    for (auto i = values.begin(); i != values.end(); i++)
    {
        nodes.emplace_back(new TreeNode(*i));
    }
    nodes[0]->left = nodes[1].get();
    nodes[0]->right = nodes[2].get();
    vector<int> output = {2, -3, 4};
    EXPECT_EQ(solution.findFrequentTreeSum(nodes[0].get()), output);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> values = {5, 2, -5};
    vector<unique_ptr<TreeNode>> nodes;
    for (auto i = values.begin(); i != values.end(); i++)
    {
        nodes.emplace_back(new TreeNode(*i));
    }
    nodes[0]->left = nodes[1].get();
    nodes[0]->right = nodes[2].get();
    vector<int> output = {2};
    EXPECT_EQ(solution.findFrequentTreeSum(nodes[0].get()), output);
}