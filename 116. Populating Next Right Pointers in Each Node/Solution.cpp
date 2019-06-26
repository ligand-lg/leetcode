//
// Created by fry on 2019-05-17
//

/**
 *
 * T(n) = O(n)
 * S(n) = O(n)
 */

#include "../leetcode.h"

class Solution {
  void help(Node *left, Node *right) {
    if (left == nullptr)
      return;
    left->next = right;
    help(left->left, left->right);
    help(left->right, right->left);
    help(right->left, right->right);
  }
 public:
  Node *connect(Node *root) {
    if (root != nullptr)
      help(root->left, root->right);
    return root;
  }
};
