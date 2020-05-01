#pragma once
#include "Common.h"

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution
{
public:
    Node* cloneGraph(Node* node)
    {
        if (node == nullptr)
            return nullptr;
        return visit(node);
    }
private:
    Node* visit(Node* node)
    {
        auto it = visitedNodes.find(node);
        if (it != visitedNodes.end())
        {
            return it->second;
        }
        
        Node* result = new Node(node->val);
        visitedNodes.emplace(node, result);
        for (auto i : node->neighbors)
        {
            result->neighbors.emplace_back(visit(i));
        }
        
        return result;
    }
    map<Node*, Node*> visitedNodes;
};

void Test()
{
    
}
