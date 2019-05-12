//
// Created by ligand on 2019-05-11.
//

/**
 * T(n) = O(n)
 * S(n) = O(depth(tree))
 */

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
 public:
  int maxDepth(TreeNode *root) {
    if (!root) {
      return 0;
    }
    int left_depth = maxDepth(root->left);
    int right_depth = maxDepth(root->right);
    return (left_depth > right_depth ? left_depth : right_depth) + 1;
  }
};
