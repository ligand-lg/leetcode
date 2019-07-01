/**
 *
 * T(n) = O(n)
 * S(n) = O(h)
 */

#include "../leetcode.h"

class Solution {
 public:
  void recoverTree(TreeNode *root) {
    if (root == nullptr)
      return;
    TreeNode *a, *b, *pre;
    a = b = nullptr;
    TreeNode min_node(INT_MIN);
    pre = &min_node;
    stack<TreeNode *> sta;

    TreeNode *node = root;
    // 中序遍历的循环实现
    while (!sta.empty() || node != nullptr) {
      // 1. 左边进栈
      while (node != nullptr) {
        sta.push(node);
        node = node->left;
      }
      // 2. 处理栈顶
      node = sta.top();
      sta.pop();
      if (node->val < pre->val) {
        b = node;
        if (a == nullptr) {
          a = pre;
        } else {
          break;
        }
      }
      // 3. 下一个元素为当前元素的右节点
      pre = node;
      node = node->right;
    }

    int tmp = a->val;
    a->val = b->val;
    b->val = tmp;
  }
};
