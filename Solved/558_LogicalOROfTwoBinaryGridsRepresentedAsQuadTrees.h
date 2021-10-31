#pragma once
#include "Common.h"

// Definition for a QuadTree node.
class Node
{
public:
    bool val;
    bool isLeaf;
    Node *topLeft;
    Node *topRight;
    Node *bottomLeft;
    Node *bottomRight;

    Node()
    {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf)
    {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf, Node *_topLeft, Node *_topRight, Node *_bottomLeft, Node *_bottomRight)
    {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};

class Solution
{
public:
    Node *intersect(Node *quadTree1, Node *quadTree2)
    {
        if (quadTree1->isLeaf && quadTree2->isLeaf)
        {
            Node *result = new Node(quadTree1->val | quadTree2->val, true);
            return result;
        }

        Node *topLeft, *topRight, *bottomLeft, *bottomRight;
        if (!quadTree1->isLeaf && !quadTree2->isLeaf)
        {
            topLeft = intersect(quadTree1->topLeft, quadTree2->topLeft);
            topRight = intersect(quadTree1->topRight, quadTree2->topRight);
            bottomLeft = intersect(quadTree1->bottomLeft, quadTree2->bottomLeft);
            bottomRight = intersect(quadTree1->bottomRight, quadTree2->bottomRight);
        }
        else
        {
            Node *nonLeaf = quadTree1;
            Node *leaf = quadTree2;
            if (quadTree1->isLeaf)
            {
                nonLeaf = quadTree2;
                leaf = quadTree1;
            }
            topLeft = intersect(leaf, nonLeaf->topLeft);
            topRight = intersect(leaf, nonLeaf->topRight);
            bottomLeft = intersect(leaf, nonLeaf->bottomLeft);
            bottomRight = intersect(leaf, nonLeaf->bottomRight);
        }

        if (topLeft->isLeaf && topRight->isLeaf && bottomLeft->isLeaf && bottomRight->isLeaf && topLeft->val == topRight->val && topLeft->val == bottomLeft->val && topLeft->val == bottomRight->val)
        {
            return topLeft;
        }
        Node *result = new Node(0, false, topLeft, topRight, bottomLeft, bottomRight);
        return result;
    }
};

class LeetCodeTest : public testing::Test
{
public:
    inline static Solution solution;
};
