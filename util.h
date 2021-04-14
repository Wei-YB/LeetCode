#pragma once


// standard library for solution
#define _USE_MATH_DEFINES

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
#include <random>


// enable some constants in math.h


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
     template<typename T>
     void print_vector(const std::vector<T>& vec) {
         for (const auto& val : vec) {
             std::cout << val << " ";
         }
     }



     template<typename T>
     void print_matrix(const std::vector<std::vector<T>>& matrix) {
         for (const auto& vec : matrix) {
             print_vector(vec);
             std::cout << std::endl;
         }
     }

     inline void parse_int(const string& str, int& index, vector<int>& data);

     inline void parse_comma(const string& str, int& index, vector<int>& data) {

         while (str[index] == ' ') {
             ++index;
         }

         if (str[index] == ',') {
             parse_int(str, ++index, data);
         }
         else if (str[index] == ']') {
             ++index;
             return;
         }
         else {
             throw std::invalid_argument("bad comma");
         }
     }

     inline void parse_int(const string& str, int& index, vector<int>& data) {
         while (str[index] == ' ') { ++index; }
         int number = 0;
         if (!isdigit(str[index])) {
             throw std::invalid_argument("bad number");
         }
         else {
             number = static_cast<int>(str[index] & 0x0f);
             ++index;
         }
         while (isdigit(str[index])) {
             number = number * 10 + static_cast<int>(str[index++] & 0x0f);
         }
         data.push_back(number);
         parse_comma(str, index, data);
     }

     inline int parse_json_vec(const string& str, int& index, vector<int>& data) {
         while (str[index] == ' ') { ++index; }
         if (str[index] == '[') {
             parse_int(str, ++index, data);
             return index;
         }
         else
             throw std::invalid_argument("bad start [");
     }

     inline vector<int> get_vec_data(const string& str)
     {
         vector<int> result;
         int index = 0;
         parse_json_vec(str, index, result);
         return result;
     }

     inline void parse_json_matrix_unwarp(const string& str, int& index, vector<vector<int>>& data)
     {
         do
         {
             vector<int> temp;
             index = parse_json_vec(str, index, temp);
             data.push_back(temp);
             while (str[index] == ' ') { ++index; }
             if (str[index] == ',')
             {
                 ++index;
             }
             else
             {
                 break;
             }
         } while (true);
         if (str[index] == ']')
             return;
         else
             throw std::invalid_argument("bad end");
     }


     inline void parse_json_matrix(const string& str, int& index, vector<vector<int>>& data)
     {
         while (str[index] == ' ') { ++index; }
         if (str[index] == '[')
         {
             parse_json_matrix_unwarp(str, ++index, data);
         }
     }


     inline vector<vector<int>> get_matrix_data(const string& str)
     {
         vector<vector<int>> result;
         int index = 0;
         parse_json_matrix(str, index, result);
         return result;
     }

 }