//
// Created by ligand on 2019-05-14.
//

/**
 * T(n) = O(n)
 * S(n) = O(n)
 */

#include <queue>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left, *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
 public:
  bool isSymmetric(TreeNode *root) {
    if (root == nullptr)
      return true;

    queue<TreeNode *> tmp;
    TreeNode *p, *q;
    tmp.push(root->left);
    tmp.push(root->right);

    while(!tmp.empty()) {
      p = tmp.front();
      tmp.pop();
      q = tmp.front();
      tmp.pop();

      if ((p == nullptr && q != nullptr) || (q == nullptr && p != nullptr))
        return false;

      if (p != nullptr) {
        if (p->val != q->val)
          return false;
        tmp.push(p->left);
        tmp.push(q->right);
        tmp.push(p->right);
        tmp.push(q->left);
      }
    }
    return true;
  }
};
