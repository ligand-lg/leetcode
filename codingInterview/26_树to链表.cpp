#include "../leetcode.h"

class Solution {
  void convert_help(TreeNode *root, TreeNode **prev) {
    if (root == nullptr) 
      return;
    convert_help(root->left, prev);
    if ((*prev) != nullptr) 
      (*prev)->right = root;
    root->left = *prev;
    (*prev) = root;
    convert_help(root->right, prev);
  }
public:
    TreeNode* Convert(TreeNode* pRootOfTree) {
      if (pRootOfTree == nullptr)
        return nullptr;
      TreeNode *prev = nullptr;
      convert_help(pRootOfTree, &prev);
      auto p = pRootOfTree;
      while(p->left != nullptr)
        p = p->left;
      return p;
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