#pragma once
#include "Common.h"

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution
{
public:
    Node* copyRandomList(Node* head)
    {
        Node* input = head;
        unordered_map<Node*, size_t> inputLookup;
        unordered_map<size_t, Node*> outputLookup;
        Node* output = nullptr, * result = nullptr;
        size_t index = 0;
        
        while (input != nullptr)
        {
            Node* temp = new Node(input->val);
            if (index == 0)
            {
                result = temp;
            }
            else
            {
                output->next = temp;
            }
            
            inputLookup.emplace(input, index);
            outputLookup.emplace(index, temp);
            
            output = temp;
            input = input->next;
            index++;
        }
        
        input = head;
        output = result;
        
        while (input != nullptr)
        {
            output->random = input->random == nullptr ? nullptr : outputLookup[inputLookup[input->random]];
            input = input->next;
            output = output->next;
        }
        
        return result;
    }
};

void Test()
{
    
}
