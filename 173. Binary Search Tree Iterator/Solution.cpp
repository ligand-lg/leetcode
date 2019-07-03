/**
 *
 * T(n) = O(n)
 * S(n) = O(h)
 */

#include "../leetcode.h"

class BSTIterator {
  stack<TreeNode *> data;
 public:
  BSTIterator(TreeNode *root) {
    while (root != nullptr) {
      data.push(root);
      root = root->left;
    }
  }

  /** @return the next smallest number */
  int next() {
    auto node = data.top();
    data.pop();
    int res = node->val;
    node = node->right;
    while (node != nullptr) {
      data.push(node);
      node = node->left;
    }
    return res;
  }

  /** @return whether we have a next smallest number */
  bool hasNext() {
    return !data.empty();
  }
};

