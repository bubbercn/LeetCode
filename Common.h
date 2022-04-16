#pragma once

#include <vector>
#include <map>
#include <assert.h>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <iostream>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <sstream>
#include <random>
#include <bitset>
#include <cmath>
#include <regex>
#include <gtest/gtest.h>

using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
