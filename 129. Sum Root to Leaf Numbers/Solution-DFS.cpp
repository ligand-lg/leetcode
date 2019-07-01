
/**
 *
 * T(n) = O(n)
 * S(n) = O(h)
 */

#include "../leetcode.h"

class Solution {
  int dfs(TreeNode *root, int sum) {
    int now_level = sum * 10 + root->val;
    if (root->left == nullptr && root->right == nullptr)
      return now_level;
    if (root->left == nullptr)
      return dfs(root->right, now_level);
    if (root->right == nullptr)
      return dfs(root->left, now_level);
    return dfs(root->left, now_level) + dfs(root->right, now_level);
  }
 public:
  int sumNumbers(TreeNode *root) {
    if (root == nullptr)
      return 0;
    return dfs(root, 0);
  }
};

int main() {
  Solution s;
  auto root = Utils::str_to_tree("[1,2,3]");
  s.sumNumbers(root);
}
