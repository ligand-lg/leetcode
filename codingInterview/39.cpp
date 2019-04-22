//
// Created by ligand on 2019-04-22.
//

#include "../leetcode.h"

class Solution {
 public:
  bool IsBalanced_Solution(TreeNode *pRoot) {
    return helper(pRoot) >= 0;
  }
  int helper(TreeNode *root) {
    int result = 0;
    if (root != nullptr) {
      int left = helper(root->left);
      int right = helper(root->right);
      int diff = left - right;
      if (left >= 0 && right >= 0 && diff <= 1 && diff >= -1) {
        result = max(left, right) + 1;
      } else {
        result = -1;
      }
    }
    return result;
  }
};
