/**
 *
 * T(n) = O(n)
 * S(n) = O(1)
 */

class Node {
 public:
  int val;
  Node *left;
  Node *right;
  Node *next;

  Node() {}

  Node(int _val, Node *_left, Node *_right, Node *_next) {
    val = _val;
    left = _left;
    right = _right;
    next = _next;
  }
};

#include "../leetcode.h"

class Solution {
 public:
  Node *connect(Node *root) {
    auto new_root = root;
    Node dumpy_level_head;
    while (new_root != nullptr) {
      Node *p = &dumpy_level_head;
      p->next = nullptr;
      while (new_root != nullptr) {
        if (new_root->left != nullptr) {
          p->next = new_root->left;
          p = p->next;
        }
        if (new_root->right != nullptr) {
          p->next = new_root->right;
          p = p->next;
        }
        new_root = new_root->next;
      }
      new_root = dumpy_level_head.next;
    }
    return root;
  }
};
