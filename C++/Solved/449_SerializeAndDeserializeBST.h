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

class Codec
{
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        stringstream stream;
        writeToStream(stream, root);
        return stream.str();
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(const string &data)
    {
        stringstream stream(data);
        return readFromStream(stream);
    }

private:
    void writeToStream(stringstream &stream, TreeNode *root)
    {
        if (root == nullptr)
        {
            stream << "N ";
            return;
        }

        stream << "Y " << root->val << " ";
        writeToStream(stream, root->left);
        writeToStream(stream, root->right);
    }
    TreeNode *readFromStream(stringstream &stream)
    {
        string tag;
        stream >> tag;
        if (tag == "N")
            return nullptr;

        int value = 0;
        stream >> value;
        TreeNode *root = new TreeNode(value);
        root->left = readFromStream(stream);
        root->right = readFromStream(stream);
        return root;
    }
};

class LeetCodeTest : public testing::Test
{
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
    Codec c;
    string tree = c.serialize(nodes[0].get());
    TreeNode *root = c.deserialize(tree);
}
