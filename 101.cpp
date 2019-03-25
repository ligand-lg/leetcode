#include "leetcode.h"

class Solution {
  bool isSymmetricTwo(TreeNode *left, TreeNode *right) {
    bool result = false;
    if (left == NULL && right == NULL) {
      result = true;
    } else if (left && right) {
      result = left->val == right->val &&
               isSymmetricTwo(left->left, right->right) &&
               isSymmetricTwo(left->right, right->left);
    }
    return result;
  }

 public:
  bool isSymmetric(TreeNode *root) {
    bool result = true;
    if (root) {
      result = isSymmetricTwo(root->left, root->right);
    }
    return result;
  }
};