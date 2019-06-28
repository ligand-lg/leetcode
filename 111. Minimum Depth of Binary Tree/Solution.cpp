/**
 *
 * T(n) = O(n)
 * S(n) = O(n)
 */

#include "../leetcode.h"

class Solution {
 public:
  int minDepth(TreeNode *root) {
    if (root == nullptr)
      return 0;
    int left = minDepth(root->left);
    int right = minDepth(root->right);
    if (left == 0 || right == 0)
      return max(left, right) + 1;
    return min(left, right) + 1;
  }
};
