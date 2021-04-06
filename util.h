#pragma once


// standard library for solution
#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <memory>
#include <set>
#include <queue>
#include <list>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <stack>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};


// TODO need to add some func in this namespace
// formatter used to test
 namespace test {
//
//     template <typename Type>
//     vector<Type> toVec(std::string& str) {
//         return {};
//     }
//
//     template <>
//     vector<string> toVec(std::string& str) {
//         
//     }
//
 }