//
// Created by ligand on 2019-05-11.
//

/**
 * 用 stack 来实现树的中序遍历
 * T(n) = O(n)
 * S(n) = O(n)
 */

#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
 public:
  vector<int> inorderTraversal(TreeNode *root) {
    vector<int> res;
    if (root == nullptr)
      return res;

    stack<TreeNode *> tmp;
    TreeNode *p = root;
    do {
      while (p != nullptr) {
        tmp.push(p);
        p = p->left;
      }
      p = tmp.top();
      tmp.pop();
      res.push_back(p->val);
      p = p->right;
    } while (!(tmp.empty() && p == nullptr));
    return res;
  }
};
