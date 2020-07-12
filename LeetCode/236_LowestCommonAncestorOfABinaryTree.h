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
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        this->p = p;
        this->q = q;
        state = State::Default;

        helper(root);
        return this->p;
    }

private:
    void visit(TreeNode *node)
    {
        if (state == State::Default)
        {
            if (node == p)
            {
                state = State::FoundOneNode;
            }
            else if (node == q)
            {
                state = State::FoundOneNode;
                swap(p, q);
            }
        }
        else if (state == State::FoundOneNode)
        {
            if (node == q)
            {
                state = State::FoundTwoNodes;
            }
        }
    }
    void helper(TreeNode *root)
    {
        if (!root)
            return;

        visit(root);

        if (state == State::FoundTwoNodes)
        {
            return;
        }

        State t1 = state;

        helper(root->left);

        if (state == State::FoundTwoNodes)
        {
            return;
        }

        State t2 = state;
        helper(root->right);
        if (t1 == State::Default && t2 == State::FoundOneNode && state == State::FoundTwoNodes)
        {
            p = root;
        }
    }
    TreeNode *p;
    TreeNode *q;
    enum class State
    {
        Default,
        FoundOneNode,
        FoundTwoNodes,
    };
    State state;
};

void Test()
{
    vector<int> values = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    vector<unique_ptr<TreeNode>> nodes;
    for (auto i = values.begin(); i != values.end(); i++)
    {
        nodes.emplace_back(new TreeNode(*i));
    }
    nodes[3]->left = nodes[5].get();
    nodes[3]->right = nodes[1].get();
    nodes[5]->left = nodes[6].get();
    nodes[5]->right = nodes[2].get();
    nodes[2]->left = nodes[7].get();
    nodes[2]->right = nodes[4].get();
    nodes[1]->left = nodes[0].get();
    nodes[1]->right = nodes[8].get();
    Solution solution;
    solution.lowestCommonAncestor(nodes[3].get(), nodes[5].get(), nodes[1].get());
}