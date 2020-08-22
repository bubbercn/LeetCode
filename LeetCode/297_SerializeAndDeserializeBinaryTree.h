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
        ostringstream stream;
        writeTreeNodeToStream(root, stream);
        return stream.str();
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(const string &data)
    {
        istringstream stream(data);
        return readTreeNodeFromStream(stream);
    }

private:
    void writeTreeNodeToStream(const TreeNode *node, ostringstream &stream)
    {
        if (node)
        {
            stream << true << " ";
            stream << node->val << " ";
            writeTreeNodeToStream(node->left, stream);
            writeTreeNodeToStream(node->right, stream);
        }
        else
        {
            stream << false << " ";
        }
    }

    TreeNode *readTreeNodeFromStream(istringstream &stream)
    {
        bool hasNode = false;
        stream >> hasNode;
        if (hasNode)
        {
            TreeNode *node = new TreeNode(0);
            stream >> node->val;
            node->left = readTreeNodeFromStream(stream);
            node->right = readTreeNodeFromStream(stream);
            return node;
        }
        else
        {
            return nullptr;
        }
    }
};

void Test()
{
    vector<int> values = {1, 2, 3, 5, 5};
    vector<unique_ptr<TreeNode>> nodes;
    for (auto i = values.begin(); i != values.end(); i++)
    {
        nodes.emplace_back(new TreeNode(*i));
    }
    nodes[0]->left = nodes[1].get();
    nodes[0]->right = nodes[2].get();
    nodes[2]->left = nodes[3].get();
    nodes[2]->right = nodes[4].get();
    // Your Codec object will be instantiated and called as such:
    Codec codec;
    string temp = codec.serialize(nodes[0].get());
    codec.deserialize(temp);
}