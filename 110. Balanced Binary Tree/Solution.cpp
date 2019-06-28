/**
 *
 * T(n) = O(n)
 * S(n) = O(n)
 */

#include "../leetcode.h"

class Solution {
  int depth(TreeNode *node) {
    if (node == nullptr)
      return 0;
    int left = depth(node->left);
    if (left < 0)
      return left;
    int right = depth(node->right);
    if (right < 0)
      return right;
    auto diff = abs(left - right);
    if (diff > 1)
      return -1;
    return max(left, right) + 1;
  }
 public:
  bool isBalanced(TreeNode *root) {
    return depth(root) >= 0;
  }
};
