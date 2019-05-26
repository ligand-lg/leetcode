
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
