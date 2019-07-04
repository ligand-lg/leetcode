/**
 *
 * T(n) = O(n)
 * S(n) = O(n)
 */

#include "../leetcode.h"

class Solution {
 public:
  int sumOfLeftLeaves(TreeNode *root, bool is_left = false) {
    if (root == nullptr)
      return 0;
    if (root->left == nullptr && root->right == nullptr)
      return is_left ? root->val : 0;
    return sumOfLeftLeaves(root->left, true) + sumOfLeftLeaves(root->right, false);
  }
};
