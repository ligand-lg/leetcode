
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
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct RandomListNode {
  int label;
  struct RandomListNode *next, *random;
  RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

TreeNode *strToNode(const string &str) {
  if (str == "null")
    return nullptr;
  int val = stoi(str);
  return new TreeNode(val);
}


// 快速构建二叉树
TreeNode *deserialize(string data) {
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
    nodes.push_back(strToNode(token));
    data.erase(0, pos + delimiter.length());
  }
  // 最后还有一个
  nodes.push_back(strToNode(data));

  // 连接各个 node
  int i = 0;
  queue<TreeNode *> tmp;
  tmp.push(nodes[i++]);
  while (i < nodes.size()) {
    auto ele = tmp.front();
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
void print_tree(TreeNode *pRoot) {
  queue<TreeNode *> que1;
  queue<TreeNode *> que2;
  vector<vector<int>> result;

  que1.push(pRoot);
  while (!que1.empty()) {
    vector<int> r1;
    while (!que1.empty()) {
      TreeNode *next = que1.front();
      if (next != nullptr) {
        r1.push_back(next->val);
        que2.push(next->left);
        que2.push(next->right);
      }
      que1.pop();
    }
    if (!r1.empty())
      result.push_back(r1);

    vector<int> r2;
    while (!que2.empty()) {
      TreeNode *next = que2.front();
      if (next != nullptr) {
        r2.push_back(next->val);
        que1.push(next->left);
        que1.push(next->right);
      }
      que2.pop();
    }
    if (!r2.empty())
      result.push_back(r2);
  }

  for (auto line : result) {
    for (auto a:line) {
      cout << a << " ";
    }
    cout << endl;
  }
}

// 116
/**
class Node {
 public:
  int val;
  Node *left;
  Node *right;
  Node *next;
  Node() {}
  Node(int _val, Node *_left, Node *_right, Node *_next) :
      val(_val), left(_left), right(_right), next(_next) {}
};
 */

// 138
class Node {
 public:
  int val;
  Node *next, *random;
  Node() : val(0), next(nullptr), random(nullptr) {}
  Node(int _val, Node *_next, Node *_random) : val(_val), next(_next), random(_random) {}
};

#endif
