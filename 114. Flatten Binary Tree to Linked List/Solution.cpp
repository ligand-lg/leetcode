/**
 *
 * T(n) = O(n)
 * S(n) = O(n)
 */

#include "../leetcode.h"

class Solution {
  pair<TreeNode *, TreeNode *> aux(TreeNode *root) {
    if (root->left == nullptr && root->right == nullptr) {
      return make_pair(root, root);
    } else if (root->left == nullptr) {
      auto right_flatten = aux(root->right);
      root->right = right_flatten.first;
      return make_pair(root, right_flatten.second);
    } else if (root->right == nullptr) {
      auto left_flatten = aux(root->left);
      root->right = left_flatten.first;
      root->left = nullptr;
      left_flatten.second->right = nullptr;
      return make_pair(root, left_flatten.second);
    } else {
      auto left_flatten = aux(root->left);
      auto right_flatten = aux(root->right);
      root->right = left_flatten.first;
      root->left = nullptr;
      left_flatten.second->right = right_flatten.first;
      return make_pair(root, right_flatten.second);
    }
  }
 public:
  void flatten(TreeNode *root) {
    if (root == nullptr)
      return;
    aux(root);
  }
};

int main() {
  auto root = deserialize("[1,2,5,3,4,null,6]");
  Solution s;
  s.flatten(root);
  cout << root;
}
