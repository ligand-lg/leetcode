#include "../leetcode.h"

class Solution {
  // 中序遍历
  void helper(TreeNode *root, TreeNode **last) {
    if (root == nullptr) return;
    helper(root->left, last);
    root->left = *last;
    if ((*last) != nullptr) {
      (*last)->right = root;
    }
    (*last) = root;
    helper(root->right, last);
  }
public:
    TreeNode* Convert(TreeNode* pRootOfTree) {
      if (pRootOfTree == nullptr)
        return nullptr;
      TreeNode *last = nullptr;
      helper(pRootOfTree, &last);
      TreeNode *newHead = pRootOfTree;
      while (newHead->left != nullptr)
        newHead = newHead->left;
      return newHead;
    }
};

int main() {
  Solution s;
  TreeNode test_case(2);
  test_case.left = new TreeNode(1);
  test_case.right = new TreeNode(3);
  auto r  = s.Convert(&test_case);
  while (r != nullptr) {
    cout << r->val << "\t";
    r = r->right;
  }
  return 0;
}