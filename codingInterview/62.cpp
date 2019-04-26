//
// Created by ligand on 2019-04-25.
//

#include "../leetcode.h"

class Solution {
  int _k = 0;
  TreeNode *mid(TreeNode *root) {
    if (root == nullptr)
      return nullptr;
    TreeNode *result = mid(root->left);
    if (result != nullptr)
      return result;
    if (_k == 1)
      return root;
    _k--;
    return mid(root->right);
  }

 public:
  TreeNode *KthNode(TreeNode *pRoot, int k) {
    if (pRoot == nullptr || k <= 0)
      return nullptr;
    _k = k;
    return mid(pRoot);
  }
};
