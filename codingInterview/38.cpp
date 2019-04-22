//
// Created by ligand on 2019-04-22.
//

#include "../leetcode.h"

class Solution {
 public:
  int TreeDepth(TreeNode *pRoot) {
    if (pRoot == nullptr) return 0;
    return max(TreeDepth(pRoot->left), TreeDepth(pRoot->right)) + 1;
  }
};
