//
// Created by ligand on 2019-05-13.
//

/**
 * T(n) = O(n)
 * S(n) = O(n)
 */

#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left, *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
 public:
  vector<vector<int>> levelOrder(TreeNode *root) {
    vector<vector<int>> res;
    queue<TreeNode *> que1, que2;
    que1.push(root);

    while (!(que1.empty() && que2.empty())) {
      vector<int> level1, level2;
      TreeNode *node;

      while (!que1.empty()) {
        node = que1.front();
        que1.pop();
        if (node != nullptr) {
          level1.push_back(node->val);
          que2.push(node->left);
          que2.push(node->right);
        }
      }
      if (!level1.empty())
        res.push_back(level1);

      while (!que2.empty()) {
        node = que2.front();
        que2.pop();
        if (node != nullptr) {
          level2.push_back(node->val);
          que1.push(node->left);
          que1.push(node->right);
        }
      }
      if (!level2.empty())
        res.push_back(level2);
    }

    return res;
  }
};
