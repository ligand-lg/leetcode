//
// Created by fry on 2019-05-25
//

/**
 *
 * T(n) = O(n)
 * S(n) = O(n)
 */

#include "../leetcode.h"

class Solution {
  pair<int, int> help(TreeNode *root) {
    auto max_min = make_pair(root->val, root->val);

    if (res && root->left) {
      auto left_max_min = help(root->left);
      if (left_max_min.first >= root->val) {
        res = false;
        return max_min;
      }
      max_min.second = left_max_min.second;
    }

    if (res && root->right) {
      auto right_max_min = help(root->right);
      if (right_max_min.second <= root->val) {
        res = false;
        return max_min;
      }
      max_min.first = right_max_min.first;
    }

    return max_min;
  }
  bool res = true;

 public:
  bool isValidBST(TreeNode *root) {
    if (root == nullptr)
      return true;
    help(root);
    return res;
  }
};
