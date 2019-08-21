#include "../leetcode.h"

class Solution {
  bool helper(TreeNode* a, TreeNode* b) {
    if (b == nullptr) return true;
    if (a == nullptr) return false;
    return a->val == b->val && helper(a->left, b->left) &&
           helper(a->right, b->right);
  }

 public:
  bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2) {
    if (pRoot2 == nullptr || pRoot1 == nullptr) return false;
    return helper(pRoot1, pRoot2) || HasSubtree(pRoot1->left, pRoot2) ||
           HasSubtree(pRoot1->right, pRoot2);
  }
};