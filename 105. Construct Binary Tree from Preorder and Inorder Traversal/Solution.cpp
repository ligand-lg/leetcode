//
// Created by fry on 2019-05-16
//

/**
 *
 * T(n) = O(n)
 * S(n) = O(n)
 */

#include "../leetcode.h"

class Solution {
  TreeNode *help(int pre_s, int pre_e, int in_s, int in_e) {
    if (pre_s < pre_e) {
      int root_index;
      for (root_index = in_s; root_index < in_e && in_[root_index] != pre_[pre_s]; root_index++);

      int left_root_len = root_index - in_s;
      TreeNode *root = new TreeNode(pre_[pre_s]);
      root->left = help(pre_s + 1, pre_s + left_root_len + 1, in_s, root_index - 1);
      root->right = help(pre_s + left_root_len + 1, pre_e, root_index + 1, in_e);
      return root;
    }
    return nullptr;
  }
  vector<int> pre_, in_;

 public:
  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    pre_ = preorder;
    in_ = inorder;
    return help(0, pre_.size(), 0, in_.size());
  }
};
