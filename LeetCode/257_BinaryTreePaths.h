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
    vector<string> binaryTreePaths(TreeNode *root)
    {
        vector<string> result;
        TreeNode *curNode = root;
        list<TreeNode *> path;
        while (curNode != nullptr)
        {
            path.emplace_back(curNode);
            if (curNode->left != nullptr)
            {
                curNode = curNode->left;
            }
            else if (curNode->right != nullptr)
            {
                curNode = curNode->right;
            }
            else
            {
                result.emplace_back(generatePath(path));
                curNode = getNextNode(path);
            }
        }
        return result;
    }

private:
    string generatePath(const list<TreeNode *> &path)
    {
        stringstream pathStream;
        auto it = path.begin();
        pathStream << to_string((*it)->val);
        while (++it != path.end())
        {
            pathStream << "->" << to_string((*it)->val);
        }
        return pathStream.str();
    }
    TreeNode *getNextNode(list<TreeNode *> &path)
    {
        TreeNode *child = *path.rbegin();
        path.pop_back();
        while (!path.empty())
        {
            TreeNode *parent = *path.rbegin();
            if (child == parent->left && parent->right != nullptr)
            {
                return parent->right;
            }
            else
            {
                child = parent;
                path.pop_back();
            }
        }
        return nullptr;
    }
};

void Test()
{
}