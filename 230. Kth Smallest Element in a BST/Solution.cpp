//
// Created by ligand on 2019-05-13.
//

/**
 * T(n) = O(n)
 * S(n) = O(n)
 *
 */

struct TreeNode {
  int val;
  TreeNode *left, *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
  int cnt, res;
  bool inorder(TreeNode *root) {
    if (root == nullptr)
      return false;

    // left
    if (inorder(root->left))
      return true;

    // mid
    if (cnt == 1) {
      res = root->val;
      return true;
    }

    // right
    cnt--;
    return inorder(root->right);
  }

 public:
  int kthSmallest(TreeNode *root, int k) {
    res = -1;
    if (k < 1 || root == nullptr)
      return -1;
    cnt = k;

    inorder(root);
    return res;
  }
};


