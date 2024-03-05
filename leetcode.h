
#ifndef LEETCODE_H
#define LEETCODE_H

#include <iostream>
#include <list>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <algorithm>
#include <stack>
#include <queue>
#include <math.h>
#include <stdlib.h>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  explicit ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct RandomListNode {
  int label;
  struct RandomListNode *next, *random;
  explicit RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

namespace Utils {

TreeNode *str_to_tree_node(const string &str) {
  if (str == "null")
    return nullptr;
  int val = stoi(str);
  return new TreeNode(val);
}

// 快速构建二叉树
TreeNode *str_to_tree(string data) {
  if (data == "[]")
    return nullptr;

  if (data[0] != '[' || data.back() != ']')
    return nullptr;
  // 去掉开头、结尾的[]
  data.erase(0, 1);
  data.erase(data.size() - 1, data.size());

  // 从 str 到 node，node 没有连接起来
  vector<TreeNode *> nodes;
  string delimiter = ",", token;
  size_t pos = 0;
  while ((pos = data.find(delimiter)) != string::npos) {
    token = data.substr(0, pos);
    nodes.push_back(str_to_tree_node(token));
    data.erase(0, pos + delimiter.length());
  }
  // 最后还有一个
  nodes.push_back(str_to_tree_node(data));

  // 连接各个 node
  int i = 0;
  queue<TreeNode *> tmp;
  tmp.push(nodes[i++]);
  while (i < nodes.size()) {
    TreeNode *ele = tmp.front();
    tmp.pop();
    if (ele != nullptr) {
      ele->left = nodes[i];
      tmp.push(nodes[i++]);
      ele->right = nodes[i];
      tmp.push(nodes[i++]);
    }
  }
  return nodes[0];
}

// 按行打印二叉树
void print_tree(TreeNode *root) {
  cout << "print_tree: ----------------" << endl;
  if (root != nullptr) {
    queue<TreeNode *> tmp;
    tmp.push(root);
    tmp.push(nullptr);

    while (!tmp.empty()) {
      TreeNode *next = tmp.front();
      tmp.pop();
      if (next == nullptr) {
        cout << endl;
        if (!tmp.empty()) {
          tmp.push(nullptr);
        }
      } else {
        cout << next->val << ", ";
        if (next->left != nullptr) {
          tmp.push(next->left);
        }
        if (next->right != nullptr) {
          tmp.push(next->right);
        }
      }
    }
  }
  cout << "print_tree: ----------------" << endl;
}
}

#endif
