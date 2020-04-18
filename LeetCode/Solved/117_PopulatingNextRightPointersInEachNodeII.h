#pragma once
#include "Common.h"

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution
{
public:
    Node* connect(Node* root)
    {
        if (root != nullptr)
        {
            helper(root, nullptr);
        }
        return root;
    }
private:
    void helper(Node* root, Node* next)
    {
        root->next = next;
        if (root != nullptr)
        {
            if (root->right != nullptr)
            {
                helper(root->right, getNext(next));
            }
            if (root->left != nullptr)
            {
                helper(root->left, root->right != nullptr ? root->right : getNext(next));
            }
        }
    }
    Node* getNext(Node* next)
    {
        while (next != nullptr)
        {
            if (next->left != nullptr)
                return next->left;
            if (next->right != nullptr)
                return next->right;
            next = next->next;
        }
        
        return nullptr;
    }
};

void Test()
{
    
}
