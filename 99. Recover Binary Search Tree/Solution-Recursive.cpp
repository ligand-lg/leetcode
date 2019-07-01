/**
 *
 * T(n) = O(n)
 * S(n) = O(h)
 */

#include "../leetcode.h"

class Solution {
  void inorder(TreeNode *root) {
    if (root == nullptr)
      return;
    inorder(root->left);
    // 找到一个。注意这里赋值的不同，第一个a赋值pre，第二个b赋值root
    if (root->val < pre->val) {
      b = root;
      if (a == nullptr) {
        a = pre;
      } else {
        return;
      }
    }
    pre = root;
    inorder(root->right);
  }
  // a，b分别为第一个和第二个，注意顺序。
  TreeNode *a, *b, *pre;
 public:
  void recoverTree(TreeNode *root) {
    a = b = nullptr;
    TreeNode min_node(INT_MIN);
    pre = &min_node;
    inorder(root);
    int tmp = a->val;
    a->val = b->val;
    b->val = tmp;
  }
};

