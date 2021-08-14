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
    vector<int> findMode(TreeNode *root)
    {
        return get<0>(helper(root));
    }

private:
    tuple<vector<int>, int, int, int, int, int> helper(TreeNode *node)
    {
        if (node == nullptr)
            return {{}, 0, 0, 0, 0, 0};

        auto [leftModes, leftModesCount, leftMin, leftMinCount, leftMax, leftMaxCount] = helper(node->left);
        auto [rightModes, rightModesCount, rightMin, rightMinCount, rightMax, rightMaxCount] = helper(node->right);

        int nodeValueCount = 1;
        if (leftMax == node->val)
        {
            nodeValueCount += leftMaxCount;
        }
        if (rightMin == node->val)
        {
            nodeValueCount += rightMinCount;
        }

        vector<int> result = {node->val};
        int resultCount = nodeValueCount;

        if (resultCount > leftModesCount)
        {
        }
        else if (resultCount == leftModesCount)
        {
            result = leftModes;
            if (result.empty() || result.back() != node->val)
            {
                result.emplace_back(node->val);
            }
        }
        else
        {
            result = leftModes;
            resultCount = leftModesCount;
        }

        if (resultCount > rightModesCount)
        {
        }
        else if (resultCount == rightModesCount)
        {
            for (auto mode : rightModes)
            {
                if (result.empty() || result.back() != mode)
                {
                    result.emplace_back(mode);
                }
            }
        }
        else
        {
            result = rightModes;
            resultCount = rightModesCount;
        }

        int min = leftMin, max = leftMax, minCount = leftMinCount, maxCount = leftMaxCount;
        if (leftMinCount == 0)
        {
            min = node->val;
            minCount = 1;
            max = node->val;
            maxCount = 1;
        }
        else
        {
            if (leftMin == node->val)
            {
                minCount = leftMinCount + 1;
            }
            if (leftMax == node->val)
            {
                maxCount = leftMaxCount + 1;
            }
            else
            {
                max = node->val;
                maxCount = 1;
            }
        }

        if (rightMax == 0)
        {
        }
        else
        {
            if (rightMin == min)
            {
                minCount += rightMinCount;
            }
            if (rightMax == max)
            {
                maxCount += rightMaxCount;
            }
            else
            {
                max = rightMax;
                maxCount = rightMaxCount;
            }
        }

        return {result, resultCount, min, minCount, max, maxCount};
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};

TEST_F(LeetCodeTest, Example1)
{
    vector<int> values = {1, 2, 2};
    vector<unique_ptr<TreeNode>> nodes;
    for (auto i = values.begin(); i != values.end(); i++)
    {
        nodes.emplace_back(new TreeNode(*i));
    }
    nodes[0]->right = nodes[1].get();
    nodes[1]->left = nodes[2].get();
    vector<int> output = {2};
    EXPECT_EQ(solution.findMode(nodes[0].get()), output);
}

TEST_F(LeetCodeTest, Example2)
{
    vector<int> values = {0};
    vector<unique_ptr<TreeNode>> nodes;
    for (auto i = values.begin(); i != values.end(); i++)
    {
        nodes.emplace_back(new TreeNode(*i));
    }
    vector<int> output = {0};
    EXPECT_EQ(solution.findMode(nodes[0].get()), output);
}

TEST_F(LeetCodeTest, Failure1)
{
    vector<int> values = {2, 1, 2, 1, 2};
    vector<unique_ptr<TreeNode>> nodes;
    for (auto i = values.begin(); i != values.end(); i++)
    {
        nodes.emplace_back(new TreeNode(*i));
    }
    nodes[0]->left = nodes[1].get();
    nodes[1]->right = nodes[2].get();
    nodes[2]->left = nodes[3].get();
    nodes[3]->right = nodes[4].get();
    vector<int> output = {2};
    EXPECT_EQ(solution.findMode(nodes[0].get()), output);
}

TEST_F(LeetCodeTest, Failure2)
{
    vector<int> values = {2, 1, 3, 0, 2, 2, 1, 1};
    vector<unique_ptr<TreeNode>> nodes;
    for (auto i = values.begin(); i != values.end(); i++)
    {
        nodes.emplace_back(new TreeNode(*i));
    }
    nodes[0]->left = nodes[1].get();
    nodes[0]->right = nodes[2].get();
    nodes[1]->left = nodes[3].get();
    nodes[1]->right = nodes[4].get();
    nodes[4]->left = nodes[5].get();
    nodes[5]->left = nodes[6].get();
    nodes[6]->right = nodes[7].get();
    vector<int> output = {1, 2};
    EXPECT_EQ(solution.findMode(nodes[0].get()), output);
}