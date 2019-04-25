//
// Created by ligand on 2019-04-24.
//

#include "../leetcode.h"

class Solution {
  bool helper(TreeNode *p1, TreeNode *p2) {
    if (p1 == nullptr || p2 == nullptr)
      return p1 == p2;
    return p1->val == p2->val && helper(p1->left, p2->right) && helper(p1->right, p2->left);
  }
 public:
  bool isSymmetrical(TreeNode *pRoot) {
    if (pRoot == nullptr)
      return true;
    return helper(pRoot->left, pRoot->right);
  }
};
