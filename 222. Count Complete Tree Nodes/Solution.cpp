/**
 *
 * T(n) = O()
 * S(n) = O()
 */

#include "../leetcode.h"

class Solution {
 public:
  int countNodes(TreeNode *root) {
    if (root == nullptr)
      return 0;
    return countNodes(root->left) + countNodes(root->right) + 1;
  }
};
